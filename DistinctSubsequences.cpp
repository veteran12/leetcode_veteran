class Solution {
public:
    int numDistinct(string S, string T) {
        int n = S.size();
        int m = T.size();
        int dp[n+1][m+1];
        for(int i=0; i<n+1; i++)
            dp[i][0] = 1;
        for(int i=1; i<m+1; i++)
            dp[0][i] = 0;
        
        for(int i=1; i<n+1; i++) {
            for(int j=1; j<m+1; j++) {
                if(S[i-1] == T[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};