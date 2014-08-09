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