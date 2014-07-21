class Solution {
public:
    int maxProfit(vector<int> &prices) {
        prices.push_back(0);
        int low = prices[0];
        int res = 0;
        
        for(int i=1; i<prices.size()+1; i++) {
            if (prices[i] <= prices[i-1]) {
                res += prices[i-1] - low;
                low = prices[i];
            }
        }
        return res;
    }
};