class Solution {
public:
    vector<vector<int>> grid;
    long long m, n;
    const long long inf = INT_MAX;

    vector<vector<vector<vector<long long>>>> dp;

    long long f(long long i, long long j, long long k, long long dir) {

        if(k < 0 || i < 0 || j < 0 || i >= m || j >= n) return inf;
        if(i == m-1 && j == n-1) return grid[i][j];

        if(dp[i][j][k][dir + 1] != -1)
            return dp[i][j][k][dir + 1];

        long long a = f(i+1, j, k-(dir!=2), 2);
        long long b = f(i, j+1, k-(dir!=1), 1);
        long long c = f(i-1, j, k-(dir!=0), 0);
        long long d = f(i, j-1, k-(dir!=3), 3);

        return dp[i][j][k][dir + 1] =
            min(grid[i][j] + min({a, b, c, d}), inf);
    }

    int minCost(vector<vector<int>>& Grid, int k) {
        grid = Grid;
        m = grid.size();
        n = grid[0].size();

        dp = vector<vector<vector<vector<long long>>>>(
            m + 1,
            vector<vector<vector<long long>>>(
                n + 1,
                vector<vector<long long>>(
                    k + 2,
                    vector<long long>(5, -1)
                )
            )
        );

        long long ans = f(0, 0, k + 1, -1);

        if(ans == inf) return -1;
        return ans;
    }
};