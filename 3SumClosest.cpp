class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int res = INT_MAX;
        int dis = INT_MAX;
        sort(num.begin(), num.end());
        
        int len = num.size();
        int i = 0;
        while (i < len) {
            int j = i + 1;
            int k = len - 1;
            int tmp;
            while (j < k) {
                tmp = num[i] + num[j] + num[k] - target;
                if (abs(tmp) < dis) {
                    res = num[i] + num[j] + num[k];
                    dis = abs(tmp);
                }
                if (tmp < 0) {
                    j++;
                    while (num[j-1] == num[j]) j++;
                }
                else if (tmp > 0) {
                    k--;
                    while (num[k+1] == num[k]) k--;
                }
                else
                    return res;
            }
            i++;
            while (num[i-1] == num[i]) i++;
        }
        return res;
    }
};