class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string R[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        sub(R, "", 0, digits, res);
        return res;
    }
    
    void sub(string R[], string tmp, int i, string digits, vector<string> &res) {
        if(tmp.size() == digits.size()) {
            res.push_back(tmp);
            return;
        }
        
        for(int j=0; j<R[digits[i]-'0'-2].size(); j++) {
            tmp.push_back(R[digits[i]-'0'-2][j]);
            sub(R, tmp, i+1, digits, res);
            tmp.pop_back();
        }
        return;
    }
};