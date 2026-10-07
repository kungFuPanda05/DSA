class Solution {
public:
    string s;
    int n;

    int dp[51][51];

    int f(int i, int j){
        if(i==j-1) return (s[i]=='(' && s[j]==')');
        if(i>=j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int ans = 0;

        int br = 0;
        for(int k=i; k<j; k++){
            if(s[k]=='(') br++;
            else br--;
            if(br<0) break;
            if(br==0) return dp[i][j] = f(i, k) + f(k+1, j);
        }
        return dp[i][j] = 2*f(i+1, j-1);
    }

    int scoreOfParentheses(string S) {
        s = S;
        n = s.size();
        memset(dp, -1, sizeof(dp));
        return f(0, n-1);
    }
};