class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if(board.empty())
            return;
        int M = board.size();
        int N = board[0].size();
        
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j)
                if (i == 0 || j == 0 || i == M-1 || j == N-1)
                    sub(board, i, j);
        
        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == 'A')
                    board[i][j] = 'O';
            }
        }
        
        return;
    }
    
    void sub(vector<vector<char>> &board, int row, int col) {
        if (board[row][col] != 'O') return;
        int N = board.size(), M = board[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(row, col));
        while (!q.empty())
        {
            int i = q.front().first, j = q.front().second;
            q.pop();
            if (i < 0 || i >= N || j < 0 || j >= M) continue;
            if (board[i][j] != 'O') continue;// important to recheck!
            board[i][j] = 'A';
            q.push(make_pair(i-1, j));
            q.push(make_pair(i+1, j));
            q.push(make_pair(i, j-1));
            q.push(make_pair(i, j+1));
        }
    }
};