class Solution {
public:
    static bool cmp(vector <int> a, vector <int> b){
        return (a[1]>b[1]);
    }

    int maximumUnits(vector<vector<int>>& arr, int size) {
        sort(arr.begin(), arr.end(), cmp);
        int ans = 0;
        for(auto val: arr){
            int boxes = min(size, val[0]);
            ans += boxes*val[1];
            size -= boxes;
        }
        return ans;
    }
};