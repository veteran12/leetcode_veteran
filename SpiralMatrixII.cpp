class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        int count = 1;
        vector<int> tmp(n, 0);
        vector<vector<int> > res(n, tmp);
        
        for(int i=0; i<=n/2; i++) {
            for(int k=i; k<n-i; k++) {
                res[i][k] = count;
                count++;
            }
            for(int k=i+1; k<n-i; k++) {
                res[k][n-i-1] = count;
                count++;
            }
            for(int k=n-i-2; k>=i; k--) {
                res[n-i-1][k] = count;
                count++;
            }
            for(int k=n-i-2; k>i; k--) {
                res[k][i] = count;
                count++;
            }
        }
        return res;
    }
};