class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.size() > 12)
            return res;
        sub(res, s, 4, "");
        return res;
    }
    
    void sub(vector<string> &res, string s, int count, string tmp) {
        if(s.size() == 0) {
            if(count == 0) {
                tmp.pop_back();
                res.push_back(tmp);
            }
            return;
        }
        
        for(int i=1; i<=3 && i<=s.size(); i++) {
            if(i==3 && atoi(s.substr(0,3).c_str())>255)
                return;
            string Ltmp = tmp + s.substr(0, i) + '.';
            sub(res, s.substr(i), count-1, Ltmp);
            if(s[0] == '0')
                break;
        }
        return;
    }
    
};