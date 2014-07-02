class Solution {
public:
    bool isValid(string s) {
        vector<char> tmp;
        
        for (int i=0; i<s.size(); i++) {
            if (s[i]=='(' || s[i]=='[' || s[i]=='{')
                tmp.push_back(s[i]);
            else {
                if (tmp.empty())
                    return false;
                else {
                    if ((s[i]==')' && tmp.back()=='(') || (s[i]==']' && tmp.back()=='[') ||(s[i]=='}' && tmp.back()=='{')) {
                    tmp.pop_back();
                    }
                    else
                        return false;
                }
                    
            }
        }
        if (tmp.empty())
            return true;
        return false;
    }
};