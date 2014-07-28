#!/usr/bin/env python
class Solution:
    # @param grid, a list of lists of integers
    # @return an integer
    def minPathSum(self, grid):
        i = len(grid)
        j = len(grid[0])
        dp = [[0 for col in range(j)] for row in range(i)]
        
        dp[0][0] = grid[0][0]
        
        for m in range(1,i):
            dp[m][0] = dp[m-1][0] + grid[m][0]        
        for n in range(1,j):
            dp[0][n] = dp[0][n-1] + grid[0][n]
        
        for m in range(1,i):
            for n in range(1,j):
                dp[m][n] = min(dp[m-1][n], dp[m][n-1]) + grid[m][n]
                
        return dp[i-1][j-1]
                

