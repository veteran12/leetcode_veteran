class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        
        const char *sBackup = NULL, *pBackup = NULL;
        while (*s != '\0') {
            if (*p == '?' || *s == *p) {
                s++;
                p++;
            } else if (*p == '*') {
                while (*p == '*') p++;
                if (*p == '\0') return true;
                sBackup = s;
                pBackup = p;
            } else {
                if (!pBackup) return false; //if pBackup is not NULL, it indicate that * has been met;
                s = ++sBackup;
                p = pBackup;
            }
        }
        while (*p == '*') p++;
        return *p == '\0';
    }
};

bool isMatch_wildcard(const char *s, const char *p) {
    int N = strlen(s), M = strlen(p);
    vector<vector<bool> > dp(N + 1, vector<bool>(M + 1, false));
    dp[0][0] = true;
    for(int i = 1; i < M + 1; i++)
        if(p[i - 1] == '*')
            dp[0][i] = dp[0][i - 1];
    
    for(int i = 1; i < N + 1; i++) {
        for(int j = 1; j < M + 1; j++) {
            if(s[i - 1] == p [j - 1] || p[j - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if(p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
            }
            else
                dp[i][j] = false;
        }
    }
    return dp[N][M];
}