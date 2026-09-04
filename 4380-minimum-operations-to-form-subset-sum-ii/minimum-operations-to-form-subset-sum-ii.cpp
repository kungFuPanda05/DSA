class Solution {
public:
    vector <int> arr;
    long long n;
    const long long inf = INT_MAX-10000;
    vector <vector <long long>> dp;
    long long f(long long i, long long sum){

        if(sum==0) return 0;
        if(i==n || sum<0) return inf;
        if(dp[i][sum]!=-1) return dp[i][sum];

        long long num = arr[i];
        long long ans = f(i+1, sum);
        long long op = 0;

        while(num>0){
            ans = min(ans, op+f(i+1, sum-num));
            long long sub_op = 0;
            long long sub_num = num;
            int even = 0;
            if(num%2==0) even = 1;
            if(even){
                int count=3;
                while(count--){
                    ans = min(ans, op+sub_op+f(i+1, sum-sub_num));
                    sub_num *= 2;
                    sub_op++;
                }
            }else{
                while(sub_num<=sum){
                    ans = min(ans, op+sub_op+f(i+1, sum-sub_num));
                    sub_num *= 2;
                    sub_op++;
                }
            }
            num /= 2;
            op++;
        }
        return dp[i][sum] = min({ans, inf});
    }

    long long minOperations(vector<int>& nums, int sum) {
        arr = nums;
        n = arr.size();
        dp = vector <vector <long long>> (n+1, vector <long long> (sum+1, -1));
        long long ans = f(0, sum);
        if(ans==inf) return -1;
        return ans;
    }
};