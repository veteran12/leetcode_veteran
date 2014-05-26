/*using dp
 *using the substring length and the substring start index in the original string to build dp[][]
 */

bool wordBreak(string s, unordered_set<string> &dict) {
        int M=s.size();
        bool dp[M+1][M];
        for(int i=0;i<M+1;i++)
            for(int j=0;j<M;j++)
                dp[i][j]=false;
        for(int i=1;i<M+1;i++){
            for(int j=0;j<M-i+1;j++){
                if(dict.find(s.substr(j,i))!=dict.end()){
                    dp[i][j]=true;
                    continue;
                }
                for(int k=1;k<i;k++){
                    if(dp[k][j]&&dp[i-k][j+k]){
                        dp[i][j]=true;
                        break;
                    }
                }
            }
        }
        return dp[M][0];
    }
/*
 *again!
 *use dp. Heuristic method:if a string satisfies the requirement, then the string can
 *be divided into two substrings that both satisfy the requirement.
 *dp[m][n], m is the length of the substring and n is the start index of the substring in the original string.
 */
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int N = s.length();
        bool dp[N+1][N];
        for( int i = 0; i < N + 1; i++ )
            for( int j = 0; j < N; j++ )
                dp[i][j] = false;
        
        for( int i = 1; i < N + 1; i++ ){
            for( int j = 0; i + j < N + 1; j++ ){
                if( dict.find(s.substr(j,i)) != dict.end() ){
                    dp[i][j] = true;
                    continue;
                }
                for( int k = 1; k < i; k++ ){
                    if( dp[k][j] && dp[i-k][j+k] ){
                        dp[i][j] = true;
                        break;
                    }
                }
            }
        }
        return dp[N][0];
    }
};

/*
 *java version
 *public class Solution {
    public boolean wordBreak(String s, Set<String> dict) {
        int N = s.length();
        boolean dp[][] = new boolean[N+1][N];
        for( int i = 0; i < N + 1; i++ )
            for( int j = 0; j < N; j++ )
                dp[i][j] = false;
        
        for( int i = 0; i < N+1; i++ ){
            for( int j = 0; i + j < N + 1; j++ ){
                if( dict.contains( s.substring(j,j + i) ) ){
                    dp[i][j] = true;
                    continue;
                }
                for( int k = 1; k < i; k++ ){
                    if( dp[k][j] && dp[i-k][j+k] ){
                        dp[i][j] = true;
                        break;
                    }
                }
            }
        }
        return dp[N][0];
    }
}
 */