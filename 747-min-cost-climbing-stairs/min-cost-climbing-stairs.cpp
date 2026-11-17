class Solution {
public:
    vector <int> cost;
    int n;
    vector <int> dp;
    int f(int i){
        if(i>=n) return 0;
        if(dp[i+1]!=-1) return dp[i+1];
        return dp[i+1] = ((i>=0)?cost[i]:0) + min(f(i+1), f(i+2));
    }

    int minCostClimbingStairs(vector<int>& Cost) {
        cost = Cost;
        n = cost.size();
        dp = vector <int> (n+1, -1);
        return f(-1);
    }
};
