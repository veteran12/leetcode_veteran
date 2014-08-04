class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        vector<string> tmp;
        sub(res, s, tmp, 0, 1);
        return res;
    }
    
    void sub(vector<vector<string> > &res, string s, vector<string> &tmp, int start, int len) {
        if(start >= s.size()) {
            res.push_back(tmp);
            return; 
        }
        
        while(start+len <= s.size()) {
            if(isPalin(s.substr(start, len))) {
                tmp.push_back(s.substr(start, len));
                sub(res, s, tmp, start+len, 1);
                tmp.pop_back();
            }
            len++;
        }
        return;
    }
    
    bool isPalin(string s) {
        for(int i=0, j=s.size()-1; i<j; i++, j--) {
            if(s[i] != s[j])
                return false;
        }
        return true;
    }
};