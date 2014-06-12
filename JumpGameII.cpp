//tricky, can slightly save time

class Solution {
public:
    int jump(int A[], int n) {
        int start = 0;
        int res = 0;
        while (start < n-1)
        {
            res++;
            if (start + A[start] >= n-1)
                return res;
            int mx = start;
            for (int i = start + 1; i <= start + A[start]; ++i)
                if (i + A[i] >= mx + A[mx])//find the farthest position can reach start from 'start' index and then begin from there.
                    mx = i;
            start = mx;
        }
    }
};