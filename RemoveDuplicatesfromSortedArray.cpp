class Solution {
public:
    /*int removeDuplicates(int A[], int n) {
        int i = 1;
        while(i < n) {
            int tmp = 0;
            int x = i;
            while(x<n && A[x] == A[x-1]) {
                x++;
                tmp++;
            }
            x = i;
            while(tmp!=0 && x<n) {
                A[x] = A[x+tmp];
                x++;
            }
            n -= tmp;
            i++;
        }
        return n;
    }*/
    
    
    int removeDuplicates(int A[], int n) {
        for(int i=0;i<n-1;i++){
        int j=i+1;
        while(A[j]==A[i]&&j<n)
            j++;
        for(int h=1;j+h-1<n;h++){
            A[i+h]=A[j+h-1];
        }
        n=n-j+i+1;
    }
    return n;
    }
};