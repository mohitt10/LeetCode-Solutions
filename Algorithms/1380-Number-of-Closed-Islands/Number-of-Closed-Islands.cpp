class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> row = {0, 0, 1, -1}, col = {1, -1, 0, 0};
        for(int i = 0; i < m; i++) {
            queue<pair<int, int>> q;
            if(grid[i][0] == 0) {
                grid[i][0] = 1;
                q.push({i, 0});
            }
            if(grid[i][n - 1] == 0) {
                grid[i][n - 1] = 1;
                q.push({i, n - 1});
            }
            while(!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                for(int j = 0; j < 4; j++) {
                    int X = x + row[j], Y = y + col[j];
                    if(0 <= X && X < m && 0 <= Y && Y < n) {
                        if(grid[X][Y] == 0) {
                            grid[X][Y] = 1;
                            q.push({X, Y});
                        }
                    }
                } 
            }
        }
        for(int j = 0; j < n; j++) {
            queue<pair<int, int>> q;
            if(grid[0][j] == 0) {
                grid[0][j] = 1;
                q.push({0, j});
            }
            if(grid[m - 1][j] == 0) {
                grid[m - 1][j] = 1;
                q.push({m - 1, j});
            }
            while(!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                for(int i = 0; i < 4; i++) {
                    int X = x + row[i], Y = y + col[i];
                    if(0 <= X && X < m && 0 <= Y && Y < n) {
                        if(grid[X][Y] == 0) {
                            grid[X][Y] = 1;
                            q.push({X, Y});
                        }
                    }
                } 
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    ans++;
                    grid[i][j] = 1;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while(!q.empty()) {
                        auto [x, y] = q.front(); q.pop();
                        for(int k = 0; k < 4; k++) {
                            int X = x + row[k], Y = y + col[k];
                            if(0 <= X && X < m && 0 <= Y && Y < n) {
                                    if(grid[X][Y] == 0) {
                                    grid[X][Y] = 1;
                                    q.push({X, Y});
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};