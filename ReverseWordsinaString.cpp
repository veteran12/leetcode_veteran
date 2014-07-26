class Solution {
public:
    void reverseWords(string &s) {
        string tmp;
        int i = s.size()-1;
        int j = s.size()-1;
        while(i >= 0) {
            if(s[i] == ' ')
                i--;
            else {
                int j = i;
                while(j>=0 && s[j] != ' ') j--;
                tmp += s.substr(j+1, i-j);
                tmp.push_back(' ');
                i = j;
            }
        }
        if(tmp.back() == ' ')
            tmp.pop_back();
        s = tmp;
    }
};