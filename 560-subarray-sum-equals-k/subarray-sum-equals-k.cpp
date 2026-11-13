class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        int sum = 0;
        int ans = 0;
        m[0] = 1;
        for(auto val: arr){
            sum += val;
            if(m.find(sum-k)!=m.end()) {
                ans += m[sum-k];
            }
            m[sum]++;
        }
        return ans;
    }
};