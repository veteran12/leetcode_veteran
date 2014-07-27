class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int j = strlen(s) - 1;
        while(s[j] == ' ') j--;
        int i = j;
        while(i>=0 && s[i] != ' ') i--;
        
        return j - i;
    }
};