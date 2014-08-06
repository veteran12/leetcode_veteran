class Solution {
public:
    int candy(vector<int> &ratings) {
        int N = ratings.size();
        if (N == 0) return 0;
        int candy = 1, res = 1;
        int maxValue = 1, maxIndex = 0;
        for (int i = 1; i < N; ++i)
        {
            if (ratings[i] >= ratings[i-1]) 
            {
                candy = ratings[i] == ratings[i-1] ? 1 : candy + 1;
                maxValue = candy;
                maxIndex = i;
            }
            else
            {
                if (candy == 1) {
                    if (maxValue <= i - maxIndex) {
                        res += i - maxIndex;
                        maxValue++;
                    } else {
                        res += i - maxIndex - 1;
                    }
                }
                candy = 1;
            }
            res += candy;
        }
        return res;
    }
};