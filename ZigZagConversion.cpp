class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) return s;
        
        int gap = 2 * nRows - 2;
        string res;
        for(int i=1; i<=nRows; i++) {
            int subGap1 = (i == 1 || i == nRows)? gap : 2 * (nRows - i);
            int subGap2 = (i == 1 || i == nRows)? gap : gap - subGap1;
            int j = i - 1;
            bool isGap1 = true;
            while(j < s.size()) {
                res.push_back(s[j]);
                if(isGap1) {
                    j += subGap1;
                    isGap1 = false;
                }
                else {
                    j += subGap2;
                    isGap1 = true;
                }
            }
        }
        return res;
    }
};