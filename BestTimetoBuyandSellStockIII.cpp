class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len = prices.size();
        if (len == 0 || len == 1)
            return 0;
        vector<int> forward(len, 0);
        vector<int> backward(len, 0);
        
        int low = prices[0];
        int res = 0;
        for (int i=1; i<len; i++) {
            if(prices[i] >= low) {
                if (prices[i]  - low > res)
                    res = prices[i] - low;
            }
            else
                low = prices[i];
            forward[i] = res;
        }
        
        int high = prices.back();
        res = 0;
        for (int i=len-2; i>=0; i--) {
            if(prices[i] <= high) {
                if (high - prices[i] > res)
                    res = high - prices[i];
            }
            else
                high = prices[i];
            backward[i] = res;
        }
        
        int tmp = 0;
        for (int i=0; i<len-1; i++) {
            tmp = (forward[i] + backward[i] > tmp) ? forward[i] + backward[i] : tmp;
        }
        
        return tmp;
    }
};