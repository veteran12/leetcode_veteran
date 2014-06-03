class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        vector<vector<int> > tmp(board.size(),vector<int>(board[0].size(),0));
        for(int x = 0; x < board.size(); x++){
            for(int y = 0; y < board[0].size(); y++ ){
                if ( sub( board, tmp, word, 0, x, y ) )
                    return true;
            }
        }
        return false;
    }
    bool sub( vector<vector<char> > &board, vector<vector<int> > &tmp, string &word, int i ,int x, int y){
        if( i == word.size() ){
            return true;
        }
        if(  x < 0 || y < 0 || x >= board.size() || y>= board[0].size() || tmp[x][y] == 1 || board[x][y] != word[i] )
            return false;
        tmp[x][y] = 1;
        if( sub( board, tmp, word, i + 1, x, y + 1 ) || sub( board, tmp, word, i + 1, x + 1, y ) || sub( board, tmp, word, i + 1, x - 1, y ) || sub( board, tmp, word, i + 1, x, y-1 ))
            return true;
        tmp[x][y] = 0;
        return false;
    }
};