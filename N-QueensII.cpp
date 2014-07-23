class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<int> x(n, 0);
        vector<vector<int> > board(n,x);
        
        sub(0, n, res, board);
        return res;
    }
    
    void sub(int count, int n, int &res, vector<vector<int> > &board) {
        if(count == n) {
            res++;
            return;
        }
        int i = 0;
        while(i < n) {
            if(isValid(board, i, count)) {
                board[i][count] = 1;
                sub(count+1, n, res, board);
                board[i][count] = 0;
            }
            i++;
        }
        return;
    }
    
    bool isValid(vector<vector<int> > &board, int m, int n) {
        int len = board.size();
        for(int i=0; i<len; i++) {
            for(int j=0; j<len; j++) {
                if(board[i][j] == 1) {
                    if(i==m || j==n || i+j==m+n || i-j==m-n)
                        return false;
                }
            }
        }
        return true;
    }
};