class Solution {
public:
    vector <int> arr;
    long long n;
    vector <vector <vector <vector <long long>>>> dp;
    const long long inf = LONG_MAX-100;

    long long f(long long i, long long skipped, long long prev, int started){
        if(i==n) {
            if(!started) return -inf;
            return 0;
        }
        long long prevIdx = prev==-1?0:1;
        long long ans = -inf;
        if(dp[i][skipped][prevIdx][started]!=-inf) return dp[i][skipped][prevIdx][started];

        if(!started) {
            ans = max(ans, f(i+1, skipped, prev, started));
            
        }else{
            if(!skipped){
                ans = max(ans, f(i+1, true, prev, started));
            }
            ans = max(ans, 0LL);

        }
        ans = max(ans, -prev*arr[i] + f(i+1, skipped, prev*-1, true));

        return dp[i][skipped][prevIdx][started] = ans;
    }

    long long maxAlternatingSum(vector<int>& nums) {
        arr = nums;
        n = arr.size();
        if(n==1) return arr[0];
        dp = vector <vector <vector <vector <long long>>>> (n+1,
            vector <vector <vector <long long>>> (2, 
                vector <vector <long long>> (2, 
                    vector <long long> (2, -inf)
                )
            )
        );

        return f(0, 0, -1, 0);
    }
};