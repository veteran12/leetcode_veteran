/*check each element that is '1'
 *calculate the maximal rectangle starting from the '1'
 *to the up and right.
 *or we can change this to dp,dp[][] stores the height and length of the maximal
 *rectangle in the up right of the '1' element
 *the recursion
 *pair<int, int> dp[N][M];
        memset(dp, 0, sizeof(dp));
        int x = (j == 0) ? 1 : dp[i][j-1].first + 1;
        int y = (i == 0) ? 1 : dp[i-1][j].second + 1;
        dp[i][j] = make_pair(x, y);
                
 */

int maximalRectangle(vector<vector<char> > &matrix) {
    int M = matrix.size();
    if( M == 0 )
        return 0;
    int N = matrix[0].size();
    int res = 0;
    
    for( int i = 0; i < M; i++ ){
        for ( int j = 0; j < N; j++ ){
            if ( matrix[i][j] == '0' )
                continue;
            int minu=1, minr = 1;
            for ( int k = i-1; k>=0; k-- ){
                if( matrix[k][j] == '1' )
                    minu++;
                else
                    break;
            }
            res = max( res, minu*minr );
            
            for( int m = j+1; m < N; m++ ){
                if( matrix[i][m] =='1' ){
                    minr++;
                }
                else
                    break;
                for ( int n = i-1; n >= -1; n-- ){
                    if( n==-1 || matrix[n][m]=='0' ){
                        minu = min( minu, i-n );
                        res = max( res, minu*minr );
                        break;
                    }
                }
            }
        }
    }
    return res;
}