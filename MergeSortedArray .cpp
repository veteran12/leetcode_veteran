class Solution {
public://stupid!!!
    void merge(int A[], int m, int B[], int n) {
        int i = 0;
        int j = 0;
        
        int tmp[m];
        for (int i=0;i<m;i++)
            tmp[i] = A[i];
            
        int index = 0;
        while (i<m && j<n) {
            if (tmp[i] > B[j]) {
                A[index] = B[j];
                j++;
            }
            else {
                A[index] = tmp[i];
                i++;
            }
            index++;
        }
        if (i < m) {
            for (;i<m;i++)
                A[index++] = tmp[i]; 
        }
        if (j < n) {
            for (;j<n;j++)
                A[index++] = B[j];
        }
        return;
    }
};

void merge(int A[], int m, int B[], int n) {
        int i = m - 1;
        int j = n - 1;
        int x = m + n - 1;
        
        while (i>=0 && j>=0) {
            if (A[i] >= B[j])
                A[x--] = A[i--];
            else
                A[x--] = B[j--];
        }
        while (j>=0) {
            A[x--] = B[j--];
        }
        return;
    }