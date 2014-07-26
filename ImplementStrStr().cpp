class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int h=strlen(haystack);
        int n=strlen(needle);
        
        if(n == 0)
            return haystack;
        if(n > h)
            return NULL;
        for(int i=0; i<h-n+1; i++) {
            int hay = i;
            int nee = 0;
            while(haystack[hay] == needle[nee] && hay-i<n) {
                hay++;
                nee++;
            }
            if(hay-i == n)
                return haystack + i;
        }
        return NULL;
    }
    
};