class Solution {
public:
    void BFS(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis, int n, int m){
        vis[row][col] = 1;

        queue<pair<int,int>> q;
        q.push({row, col});

        while(!q.empty()){
            auto p = q.front();
            int r = p.first;
            int c = p.second;
            q.pop();

            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};

            for(int k = 0; k<4; k++){
                int nrow = r + delrow[k];
                int ncol = c + delcol[k];

                //check condition for the neighbor cell
                if(nrow >= 0 
                && ncol >= 0 
                && nrow < n 
                && ncol < m 
                && vis[nrow][ncol] == -1 
                && grid[nrow][ncol] == '1' ){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis (n, vector<int> (m, -1));

        int cnt = 0;

            for(int i = 0; i<n; i++){
                for(int j = 0; j<m; j++){
                    if(vis[i][j] == -1 && grid[i][j] == '1'){
                        cnt++;
                        BFS(i, j, grid, vis, n, m);
                    }
                }
            }
            return cnt;
    }
};
