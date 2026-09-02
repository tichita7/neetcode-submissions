class Solution {
public:
    void dfs(int row, int col, vector<vector<bool>>& vis, vector<vector<char>>& grid, int n, int m){
        vis[row][col] = true;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int k = 0; k<4; k++){
            int r = row + delrow[k];
            int c = col + delcol[k];

            if(r >= 0 && c >= 0 && r < n && c < m && !vis[r][c] && grid[r][c] == '1'){
                vis[r][c] = true;
                dfs(r, c, vis, grid, n, m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int cnt = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    dfs(i, j, vis, grid, n, m);
                }
            }
        }
        return cnt;
    }
};
