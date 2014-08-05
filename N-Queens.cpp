class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        string x;
        for(int i=0; i<n; i++)
            x.push_back('.');
        
        vector<string> tmp(n, x);
        sub(res, tmp, n, 0);
        return res;
    }
    
    void sub(vector<vector<string> > &res, vector<string> &tmp, int n, int count) {
        if(count == n) {
            res.push_back(tmp);
            return;
        }
        
        for(int i=0; i<n; i++) {
            if(valid(tmp,i,count)) {
                tmp[i][count] = 'Q';
                sub(res, tmp, n, count+1);
                tmp[i][count] = '.';
            }
        }
        return;
    }
    
    bool valid(vector<string> &tmp, int row, int col) {
        int N = tmp.size();
        
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(tmp[i][j] == 'Q') {
                    if(i==row || j==col || i+j==row+col || i-j==row-col)
                        return false;
                }
            }
        }
        
        return true;
    }
};