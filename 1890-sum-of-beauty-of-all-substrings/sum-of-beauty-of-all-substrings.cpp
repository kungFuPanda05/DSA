class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            unordered_map<char, int> m;
            for(int j=i; j<n; j++){
                m[s[j]]++;
                int ma=INT_MIN;
                int mi=INT_MAX;
                for(auto val: m){
                    ma = max(ma, val.second);
                    mi = min(mi, val.second);
                }
                ans += ma-mi;
            }
        }
        return ans;
    }
};