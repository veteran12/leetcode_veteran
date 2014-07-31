class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int N = triangle.back().size();
        int dp[N][N];
        dp[0][0] = triangle[0][0];
        
        for(int i=1; i<N; i++) {
            for(int j=0; j<i+1; j++) {
                if(j == 0)
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                else if(j == i)
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                else
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
            }
        }
        
        int res = INT_MAX;
        for(int i=0; i<N; i++) {
            res = min(res, dp[N-1][i]);
        }
        
        return res;
    }
};