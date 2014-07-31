class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        unordered_set<char> tmp;
        
        tmp.clear();
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.')
                    continue;
                if(tmp.find(board[i][j]) != tmp.end())
                    return false;
                tmp.insert(board[i][j]);
            }
            tmp.clear();
        }
        
        tmp.clear();
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[j][i] == '.')
                    continue;
                if(tmp.find(board[j][i]) != tmp.end())
                    return false;
                tmp.insert(board[j][i]);
            }
            tmp.clear();
        }
        
        tmp.clear();
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++){
                for(int m=3*i; m<3*i+3; m++) {
                    for(int n=3*j; n<3*j+3; n++) {
                        if(board[m][n] == '.')
                            continue;
                        if(tmp.find(board[m][n]) != tmp.end())
                            return false;
                        tmp.insert(board[m][n]);
                    }
                }
                tmp.clear();
            }
        }
        
        return true;
    }
};