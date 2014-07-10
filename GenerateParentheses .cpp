class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string tmp;
        int right = 0;
        int left = 0;
        sub(res, tmp, right, left, n);
        return res;
    }
    
    void sub(vector<string> &res, string tmp, int right, int left, int n) {
        if (tmp.size() == n*2) {
            res.push_back(tmp);
            return;
        }
        if (left >= right) {
            if (left < n) {
                tmp.push_back('(');
                sub(res, tmp, right, left+1, n);
                tmp.pop_back();
            }
            tmp.push_back(')');
            sub(res, tmp, right+1, left, n);
        }
        return;
    }
};