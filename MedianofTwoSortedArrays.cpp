class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int k = (m + n) / 2;
        if((m + n) % 2 == 1)
            return findKthSortedArrays(A, m, B, n, k+1);
        else
            return (findKthSortedArrays(A, m, B, n, k) + findKthSortedArrays(A, m, B, n, k+1)) / 2;
    }
    
    double findKthSortedArrays(int A[], int m, int B[], int n, int k) {
        if (m > n)
            return findKthSortedArrays(B, n, A, m, k);
        
        if(m == 0)
            return B[k-1];
        if(k == 1)
            return min(A[0], B[0]);
        
        int i = min(k / 2, m);
        int j = k - i;
        int a = A[i-1];
        int b = B[j-1];

        if (a < b) return findKthSortedArrays(A + i, m - i, B, n, k - i);
        else if (a > b) return findKthSortedArrays(A, m, B + j, n - j, k - j);
        else return a;
    }
};