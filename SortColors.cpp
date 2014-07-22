class Solution {
public:
     void sortColors(int A[], int n) {
        int count=0;
        int i=0;
        loop:while(i<n){
            if(A[i]==count){
                i++;
                continue;
            }
            else{
                for(int j=i+1;j<n;j++){
                    if(A[j]==count){
                        A[j]=A[i];
                        A[i]=count;
                        i++;
                        goto loop;
                    }
                }
            }
            count=(++count)%3;
        }
    }
    /*void sortColors(int A[], int n) {
        int i = 0;
        int j = n-1;
        
        for(int k=0; k<n; k++) {
            if (A[k] == 0) {
                swap(A[i], A[k]);
                i++;
            }
        }
        
        for(int k=n-1; k>=0; k--) {
            if(A[k] == 2) {
                swap(A[j], A[k]);
                j--;
            }
        }
        return;
    }*/
};