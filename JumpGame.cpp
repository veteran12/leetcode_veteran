class Solution {
public:
    bool canJump(int A[], int n) {
        for (int i=0; i<n-1; i++){
            if(A[i] == 0){
                int x = i;
                while (x >= 0){
                    if (A[x] + x > i)
                        break;
                    x--;
                }
                if (x < 0)
                    return false;
            }
        }
        return true;
    }
};