class Solution {
public:
    void dfs(vector<vector<int>>& grid, int x, int y) {
        int m = grid.size(), n = grid[0].size();
        vector<int> row = {0, 0, 1, -1}, col = {1, -1, 0, 0};
        grid[x][y] = 1;
        for(int i = 0; i < 4; i++) {
            int X = x + row[i], Y = y + col[i];
            if(0 <= X && X < m && 0 <= Y && Y < n && grid[X][Y] == 0) {
                dfs(grid, X, Y);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 0) dfs(grid, i, 0);
            if(grid[i][n - 1] == 0) dfs(grid, i, n - 1);
        }
        for(int i = 0; i < n; i++) {
            if(grid[0][i] == 0) dfs(grid, 0, i);
            if(grid[m - 1][i] == 0) dfs(grid, m - 1, i);
        }
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};