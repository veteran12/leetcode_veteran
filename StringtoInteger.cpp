class Solution {
public:
    int atoi(const char *str) {
        if (!str)
            return 0;
        while (*str == ' ')
            str++;
        
        int positive = 1;
        if (*str == '+' || *str == '-') {
            positive = (*str == '+')? 1 : 0;
            str++;
        }
        
        long long res = 0;
        while (isdigit(*str)) {
            res = res * 10 + (*str - '0');
            str++;
        }
        
        res = (positive == 1)? res : -res;
        if (res > INT_MAX) return INT_MAX;
        if (res < INT_MIN) return INT_MIN;
        
        return res;
    }
};