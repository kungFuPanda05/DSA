class Solution {
public:
    const int inf = INT_MAX-100;

    int f(vector <pair<int, int>> &arr1, vector <pair<int, int>> &arr2){
        int n1 = arr1.size();
        int n2 = arr2.size();
        sort(arr2.begin(), arr2.end());
        vector <int> right(n2, arr2.back().first+arr2.back().second);
        vector <int> left(n2, arr2[0].second);
        int ans = inf;
        int i=1;
        int j=n2-2;
        while(i<n2){
            left[i] = min(left[i-1], arr2[i].second);
            right[j] = min(right[j+1], arr2[j].first+arr2[j].second);
            i++; j--;
        }

        for(int i=0; i<n1; i++){
            int I = arr1[i].first+arr1[i].second;
            int idx = lower_bound(arr2.begin(), arr2.end(), make_pair(I, INT_MIN)) - arr2.begin();
            if(idx<n2){
                ans = min(ans, right[idx]);
            }
            if(idx-1>=0){
                ans = min(ans, I+left[idx-1]);
            }
        }
        return ans;
    }

    int earliestFinishTime(vector<int>& lst, vector<int>& ld, vector<int>& wst, vector<int>& wd) {
        vector <pair<int, int>> land;
        vector <pair<int, int>> water;

        for(int i=0; i<lst.size(); i++){
            land.push_back({lst[i], ld[i]});
        }
        for(int i=0; i<wst.size(); i++){
            water.push_back({wst[i], wd[i]});
        }
        return min(f(land, water), f(water, land));
    }
};