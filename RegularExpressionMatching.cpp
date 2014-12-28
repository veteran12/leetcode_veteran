class Solution {
public:
    bool isMatch(const char *s, const char *p){
        if( 0 == *p) return 0 == *s;  
  
        if(*(p+1) != '*')  
        {  
            if(*p == *s || (*p) == '.' && (*s) != 0)  
            {  
                return isMatch(s+1, p+1);  
            }  
            return false;  
        }  
        else  
        {  
            while(*p == *s || ((*p) == '.' && (*s) != 0))
            {  
                if(isMatch(s, p + 2))  //not use * pattern to match first
                {  
                    return true;  
                }  
                s++;  
            }  
            return isMatch(s, p + 2);  
  
        }  
    }
};


bool isMatch_Regular(const char *s, const char *p){
    int N = strlen(s), M = strlen(p);
    bool dp[N+1][M+1];
    for(int i = 0; i < N+1; i++)
        dp[i][0] = false;
    for(int i = 0; i < M+1; i++)
        dp[0][i] = false;
    dp[0][0] = true;
    
    for (int i = 2; i <= M; i ++)
        if (p[i-1] == '*') dp[0][i] = dp[0][i-2];
    
    for(int i = 1; i < N + 1; i++) {
        for(int j = 1; j < M + 1; j++) {
            if(s[i-1] == p[j-1] || p[j-1] == '.')
                dp[i][j] = dp[i-1][j-1];
            else if(p[j-1] == '*') {
                dp[i][j] = dp[i][j-2];
                if(s[i-1] == p[j-2] || p[j-2] == '.')
                    dp[i][j] = dp[i][j] | dp[i-1][j];
            }
            else {
                dp[i][j] = false;
            }
        }
    }
    return dp[N][M];
}
