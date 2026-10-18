class Solution {
public:
    static int dsum(int n){
        int sum = 0;
        while(n){
            sum += n%10;
            n /= 10;
        }
        return sum;
    }

    static bool cmp(pair<int, int> a, pair<int, int> b){
        int da = dsum(a.first);
        int db = dsum(b.first);

        if(da==db) return a.first<b.first;
        return da<db;
    }

    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        vector <pair<int, int>> v;
        for(int i=0; i<n; i++){
            v.push_back({arr[i], i});
        }
        sort(v.begin(), v.end(), cmp);

        unordered_map<int, int> m;

        for(int i=0; i<n; i++){
            m[i] = v[i].second;
        }

        vector <int> vis(n+1, 0);

        int ans = 0;

        for(int i=0; i<n; i++){
            int count = 0;
            int j = i;
            while(!vis[j]){
                vis[j] = 1;
                j = m[j];
                count++;
            }   
            ans += max(count-1, 0);
        }

        return ans;
    }
};