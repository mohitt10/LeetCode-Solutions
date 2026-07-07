class Solution {
public:
    int m, n;
    int dir[5] = {0, 1, 0, -1, 0};
    
    int dfs(vector<vector<int>>& grid, int i, int j, int l) {
        int s = 0;
        for(int k = 0; k < 4; k++) {
            int X = i + dir[k], Y = j + dir[k + 1];
            if(0 <= X && X < m && 0 <= Y && Y < n && grid[X][Y] > 0) {
                s += grid[X][Y];
                s = s % l;
                grid[X][Y] = 0;
                s += dfs(grid, X, Y, l);
            }
        }
        return s;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] > 0) {
                    int s = grid[i][j];
                    grid[i][j] = 0;
                    s += dfs(grid, i, j, k);
                    if(s % k == 0) ans++;
                }
            }
        }
        return ans;
    }
};