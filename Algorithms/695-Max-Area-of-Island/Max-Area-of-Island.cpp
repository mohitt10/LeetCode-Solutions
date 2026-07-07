class Solution {
public:
    int m, n;
    int row[4] = {1, -1, 0, 0}, col[4] = {0, 0, 1, -1};
    void dfs(vector<vector<int>>& grid, int i, int j,int& curr) {
        for(int k = 0; k < 4; k++) {
            int X = i + row[k];
            int Y = j + col[k];
            if(0 <= X && X < m && 0 <= Y && Y < n && grid[X][Y] == 1) {
                curr++;
                grid[X][Y] = 0;
                dfs(grid, X, Y, curr);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int curr = 1;
                    grid[i][j] = 0;
                    dfs(grid, i, j, curr);
                    ans = max(ans, curr);
                }
            }
        }
        return ans;
    }
};