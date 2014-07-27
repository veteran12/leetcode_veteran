class Solution {
public:
    string longestPalindrome(string s) {
        int res = 1;
        string str = s.substr(0,1);
        int len = s.size();
        
        for(int i=1; i<len; i++) {
            int j = 0;
            while(i-j-1>=0 && i+j<len && s[i-j-1]==s[i+j]) {
                j++;
                if(j*2 > res) {
                    res = j*2;
                    str = s.substr(i-j, res);
                }
            }
        }
        
        for(int i=0; i<len; i++) {
            int j = 1;
            while(i-j>=0 && i+j<len && s[i-j]==s[i+j]) {
                j++;
                if(j*2-1 > res) {
                    res = j*2-1;
                    str = s.substr(i-j+1, res);
                }
            }
        }
        
        return str;
    }
};