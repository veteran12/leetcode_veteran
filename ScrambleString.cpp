class Solution {
public:
    bool isScramble(string s1, string s2) {
        int N = s1.size();
        
        bool dp[N][N][N+1];
        memset(dp, false, sizeof(bool) * N * N * (N+1));
        
        for(int k=1; k<=N; k++) {
            for(int i=0; i<=N-k; i++) {
                for(int j=0; j<=N-k; j++) {
                    if(k == 1)
                        dp[i][j][k] = (s1[i] == s2[j]);
                    else {
                        for(int l=1; l<k; l++) {
                            if ((dp[i][j][l] && dp[i + l][j + l][k - l]) || (dp[i][j + k - l][l] && dp[i + l][j][k - l])) {  
                                dp[i][j][k] = true;  
                                break;  
                            }
                        }
                    }
                }
            }
        }
        return dp[0][0][N];
    }
};