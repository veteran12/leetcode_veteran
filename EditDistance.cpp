/*
 *use dp, a much harder version see theory of algorithm 15.5
 *the optimal solution equation see the code
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        int N = word1.length();
        int M = word2.length();
        //store the result
        int dp[N+1][M+1];
        for ( int i = 0; i < M+1; i++ )
            dp[0][i] = i;
        for ( int j = 1; j < N+1; j++ )
            dp[j][0] = j;
        
        for ( int i = 1; i < N+1; i++ ){
            for ( int j = 1; j < M+1; j++){
                if ( word1[i-1] == word2[j-1] )
                    dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = min( dp[i-1][j-1] + 1, dp[i-1][j] + 1 );
                    dp[i][j] = min( dp[i][j], dp[i][j-1] + 1 );
                }
            }
        }
        return dp[N][M];
    }
};

/*python version
  class Solution:
    # @return an integer
    def minDistance(self, word1, word2):
        n = len(word1)
        m = len(word2)
        
        dp = [ [ 0 for col in range(m+1) ] for row in range(n+1) ]
        
        for i in range(m+1):
            dp[0][i] = i
        for j in range(1,n+1):
            dp[j][0] = j
        
        for i in range(1, n+1):
            for j in range(1, m+1):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
        return dp[n][m]
        
*/
