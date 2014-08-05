class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i = 1;
        
        while(i < n) {
            int count = 1;
            while(A[i] == A[i-1] && i < n) {
                count++;
                i++;
            }
            if(count < 2)
                i++;
            else {
                int gap = count-2;
                for(int k=i-gap; k+gap<n; k++)
                    A[k] = A[k+gap];
                n-=gap;
                i-=gap;
            }
        }
        
        return n;
    }
};