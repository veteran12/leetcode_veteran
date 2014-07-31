class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int N = obstacleGrid.size();
        int M = obstacleGrid[0].size();
        int dp[N][M];
        
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                dp[i][j] = 0;
            }
        }
        
        for(int i=0; i<M; i++) {
            if(obstacleGrid[0][i] == 0)
                dp[0][i] = 1;
            if(obstacleGrid[0][i] == 1)
                break;
        }
        
        for(int i=0; i<N; i++) {
            if(obstacleGrid[i][0] == 0)
                dp[i][0] = 1;
            if(obstacleGrid[i][0] == 1)
                break;
        }
        
        for(int i=1; i<N; i++) {
            for(int j=1; j<M; j++) {
                if(obstacleGrid[i][j] == 1)
                    continue;
                else {
                    if(obstacleGrid[i-1][j] != 1)
                        dp[i][j] += dp[i-1][j];
                    if(obstacleGrid[i][j-1] != 1)
                        dp[i][j] += dp[i][j-1];
                }
            }
        }
        return dp[N-1][M-1];
    }
};