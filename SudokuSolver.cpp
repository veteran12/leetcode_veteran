class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        if(board[0][0] == '.')
            sub(board, 0, 0);
        else {
            pair<int,int> tmp;
            tmp = findNext(board, 0, 0);
            sub(board, tmp.first, tmp.second);
        }
        return;
    }
    
    int sub(vector<vector<char> > &board, int x, int y) {
        if(x == 9 && y == 9) {
            return 1;
        }
        
        pair<int,int> tmp=findNext(board, x, y);
        int m = tmp.first;
        int n = tmp.second;
        
        for (int i=1; i<=9; i++) {
            if(fit(board, x, y, i)) {
                board[x][y] = '0' + i;
                int r = sub(board, m, n);
                if(r == 1)
                    return 1;
                board[x][y] = '.';
            }
        }

        return -1;
    }
    
    bool fit(vector<vector<char> > &board, int x, int y, int val) {
        for(int i=0; i<9; i++) {
            if(board[x][i] != '.' && board[x][i] == val + '0')
                return false;
        }
        
        for(int i=0; i<9; i++) {
            if(board[i][y] != '.' && board[i][y] == val + '0')
                return false;
        }
        
        int i = (x / 3) * 3;
        int j = (y / 3) * 3;
        
        for(int m=i; m<i+3; m++) {
            for(int n=j; n<j+3; n++) {
                if(board[m][n] != '.' && board[m][n] == val + '0')
                    return false;
            }
        }
        return true;
    }
    
    pair<int,int> findNext(vector<vector<char> > &board,int row,int col){
        
        for(int k = col+1; k < 9; k++){
            if(board[row][k] != '.')
                continue;
            else
                return make_pair(row, k);
        }
        
        for(int i = row+1; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.')
                    continue;
                else
                    return make_pair(i,j);
            }
        }
        return make_pair(9,9);
    }
};