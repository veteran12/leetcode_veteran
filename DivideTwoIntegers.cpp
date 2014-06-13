class Solution {
public:
    int divide(int dividend, int divisor) {
        bool flag;
        if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
            flag = 1;
        else
            flag = 0;
        int res = 0;
        long long ddividend = abs((long long)dividend);
        long long ddivisor = abs((long long)divisor);
        while( ddivisor <= ddividend){
            long long div = ddivisor;
            int tmp = 1;
            while ((div<<1) <= ddividend) {
                div = div<<1;
                tmp = tmp<<1;
            }
            ddividend -= div;
            res +=tmp;
        }
        return flag? res : -res;
    }
};