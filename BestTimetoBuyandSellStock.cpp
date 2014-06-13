class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int N = prices.size();
        if (N == 0)
            return NULL;
        int min = prices[0];
        int max = prices[0];
        int res = 0;
        for (int i=1; i<N; i++){
            if(prices[i] > max){
                res = (prices[i]-min>res)?prices[i]-min:res;
                max = prices[i];
            }
            if(prices[i] < min){
                min = prices[i];
                max = prices[i];
            }
        }
        return res;
    }
};