class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(A[0] >= target)
            return 0;
        for(int i=0; i<n-1; i++) {
            if(A[i] == target)
                return i;
            if(A[i] < target && target < A[i+1])
                return i + 1;
        }
        if (A[n-1] >= target)
            return n - 1;
        else
            return n;
    }
};