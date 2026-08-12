class Solution {
public:
    int f(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector <vector <int>> dp(m+1, vector <int> (n+1, 0));
        vector <int> prefix(m+1, 0);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    dp[i][j] = 1+((i-1>=0 && j-1>=0)?min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]}):0);
                }
                prefix[i+1] = max({prefix[i+1], prefix[i], dp[i][j]});
            }
        }

        vector <vector <int>> dp2(m+1, vector <int> (n+1, 0));
        vector <int> suffix(m+1, 0);
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(grid[i][j]==1){
                    dp2[i][j] = 1+((i+1<m && j+1<n)?min({dp2[i+1][j], dp2[i+1][j+1], dp2[i][j+1]}):0);
                }
                suffix[i] = max({suffix[i], suffix[i+1], dp2[i][j]});
            }
        }
        int ans = 0;
        for(int i=0; i<m; i++){
            ans = max(ans, min(prefix[i], suffix[i]));
        }
        return ans;
    }

    int maxArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector <vector <int>> temp;
        for(int j=0; j<n; j++){
            vector <int> v;
            for(int i=0; i<m; i++){
                v.push_back(grid[i][j]);
            }
            temp.push_back(v);
        }
        int len = max(f(grid), f(temp));
        return len*len;
    }
};