class Solution {
public:
    int m, n;
    int dir[5] = {0, 1, 0, -1, 0};
    void dfs(vector<vector<char>>& board, int i, int j, char sym) {
        for(int k = 0; k < 4; k++) {
            int X = i + dir[k], Y = j + dir[k + 1];
            if(0 <= X && X < m && 0 <= Y && Y < n && board[X][Y] == 'O') {
                board[X][Y] = sym;
                dfs(board, X, Y, sym);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        m = board.size(); n = board[0].size();
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O') {
                board[i][0] = '#';
                dfs(board, i, 0, '#');
            }
            if(board[i][n - 1] == 'O') {
                board[i][n - 1] = '#';
                dfs(board, i, n - 1, '#');
            }
        }

        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O') {
                board[0][j] = '#';
                dfs(board, 0, j, '#');
            }
            if(board[m - 1][j] == 'O') {
                board[m - 1][j] = '#';
                dfs(board, m - 1, j, '#');
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                    dfs(board, i, j, 'X');
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};