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