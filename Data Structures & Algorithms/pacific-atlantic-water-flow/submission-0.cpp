class Solution {
private:
    void dfs(int row, int col, vector<vector<bool>>& ocean, vector<vector<int>>& heights){
        ocean[row][col] = true;

        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        for(int k = 0; k<4; k++){
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];

            if(nrow >= 0 && ncol >= 0 && nrow < heights.size() && ncol < heights[0].size() && !ocean[nrow][ncol] && heights[nrow][ncol] >= heights[row][col]){
                ocean[nrow][ncol] = true;
                dfs(nrow, ncol, ocean, heights);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));


        for(int i = 0; i<m; i++){
            dfs(0, i, pac, heights);
            dfs(n-1, i, atl, heights);
        }

        for(int i = 0; i<n; i++){
            dfs(i, 0, pac, heights);
            dfs(i, m-1, atl, heights);
        }

        vector<vector<int>> res;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(pac[i][j] && atl[i][j]){
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};
