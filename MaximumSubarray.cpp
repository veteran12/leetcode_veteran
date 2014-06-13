class Solution {
public:
    int maxSubArray(int A[], int n) {
        int res = A[0];
        int tmp = A[0];
        
        for (int i=1; i<n; i++) {
            tmp = (tmp<0)? A[i] : A[i]+tmp;
            res = max(res,tmp);
        }
        return res;
    }
};