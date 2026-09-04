class Solution {
public:
    vector <int> arr;
    int n;
    const int inf = INT_MAX-100;
    vector <vector <int>> dp;
    int f(int i, int sum){

        if(sum==0) return 0;
        if(i==n || sum<0) return inf;
        if(dp[i][sum]!=-1) return dp[i][sum];

        int num = arr[i];
        int ans = f(i+1, sum);
        int op = 0;

        while(num<=sum){
            ans = min(ans, op+f(i+1, sum-num));
            num *= 2;
            op++;
        }

        num = arr[i];
        op = 0;
        while(num>0){
            ans = min(ans, op+f(i+1, sum-num));
            num /= 2;
            op++;
        }
        return dp[i][sum] = min({ans, inf});
    }

    int minOperations(vector<int>& nums, int sum) {
        arr = nums;
        n = arr.size();
        dp = vector <vector <int>> (n+1, vector <int> (sum+1, -1));
        int ans = f(0, sum);
        if(ans==inf) return -1;
        return ans;
    }
};