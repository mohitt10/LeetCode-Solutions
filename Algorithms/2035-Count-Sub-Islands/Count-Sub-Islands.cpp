class Solution {
public:
    int m, n;
    int dir[5] = {0, 1, 0, -1, 0};

    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int& i, int& j, bool& flag) {
        for(int k = 0; k < 4; k++) {
            int X = i + dir[k], Y = j + dir[k + 1];
            if(0 <= X && X < m && 0 <= Y && Y < n && grid2[X][Y] == 1) {
                grid2[X][Y] = 0;
                if(grid1[X][Y] == 0) flag = false;
                dfs(grid1, grid2, X, Y, flag);
            }
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size(); n = grid1[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j] == 1) {
                    grid2[i][j] = 0;
                    bool flag = true;
                    if(grid1[i][j] == 0) flag = false;
                    dfs(grid1, grid2, i, j, flag);
                    ans += flag;
                }
            }
        }
        return ans;        
    }
};