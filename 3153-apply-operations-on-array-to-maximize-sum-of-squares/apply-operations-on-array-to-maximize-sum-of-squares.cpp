class Solution {
public:
    const long long mod = 1e9+7;

    int maxSum(vector<int>& arr, int k) {
        long long n = arr.size();
        unordered_map<long long, long long> m;
        for(long long i=0; i<30; i++){
            for(auto val: arr){
                m[i] += ((1<<i) & val)!=0;
            }
        }

        long long ans = 0;
        for(long long i=0; i<k; i++){
            long long num = 0;
            for(long long i=29; i>=0; i--){
                long long bit = m[i]>0?1:0;
                m[i] -= bit;
                num = num | (bit<<i);
            }
            ans = (ans + (num*num)%mod)%mod;
        }
        return ans;
    }
};