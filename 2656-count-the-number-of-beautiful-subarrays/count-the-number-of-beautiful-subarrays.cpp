class Solution {
public:
    long long beautifulSubarrays(vector<int>& arr) {
        unordered_map <long long, long long> m;
        m[0] = 1;
        long long x = 0;
        long long ans = 0;
        for(auto val: arr){
            x ^= val;
            if(m.find(x)!=m.end()) ans += m[x];
            m[x]++;
        }
        return ans;
    }
};