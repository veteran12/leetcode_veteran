class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1 << n, 0);
        for (int i = 0; i < 1 << n; ++i)
            result[i] = (i >> 1) ^ i; right move one bit and xor itself
        return result;
    }
};

  
