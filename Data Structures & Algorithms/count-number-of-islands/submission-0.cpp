class Solution {
public:
    //DFS
    void dfs(int row, int col,vector<vector<char>>& grid, vector<vector<bool>>& vis, int n, int m){
        vis[row][col] = true; //visisted

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int k = 0; k<4; k++){
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];

            if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                vis[nrow][ncol] = true;
                dfs(nrow, ncol, grid, vis, n, m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis (n, vector<bool> (m, false));

        int cnt = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(i, j, grid, vis, n, m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
