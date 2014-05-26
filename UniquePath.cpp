/*
 *using dp, this question is easy
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for( int i = 0; i < n; i++)
            dp[0][i] = 1;
        for( int j = 0; j < m; j++)
            dp[j][0] = 1;
        for( int i = 1; i < m; i++ ){
            for( int j = 1; j < n; j++ ){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

/*python version
 *class Solution:
    # @return an integer
    def uniquePaths(self, m, n):
        dp = [ [ 1 for col in range(n) ] for row in range(m) ]
        for i in range(1,m):
            for j in range(1,n):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[m-1][n-1]
*/