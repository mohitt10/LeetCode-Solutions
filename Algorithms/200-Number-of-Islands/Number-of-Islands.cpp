class Solution {
public:
    int m, n;
    int dir[5] = {0, 1, 0, -1, 0};
    void dfs(vector<vector<char>>& grid, int i, int j) {
        for(int k = 0; k < 4; k++) {
            int X = i + dir[k], Y = j + dir[k + 1];
            if(0 <= X && X < m && 0 <= Y && Y < n && grid[X][Y] == '1') {
                grid[X][Y] = '0';
                dfs(grid, X, Y);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        m = grid.size(); n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1'){
                    ans++;
                    grid[i][j] = '0';
                    dfs(grid, i, j);
                }
            }
        }
        return ans;    
    }
};