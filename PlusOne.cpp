class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int len = digits.size();
        int carry = 0;
        vector<int> res;
        digits[len-1] += 1;
        
        for(int i=len-1; i>=0; i--) {
            res.push_back((carry + digits[i]) % 10);
            carry = (carry + digits[i]) / 10;
        }
        if(carry != 0)
            res.push_back(carry);
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};