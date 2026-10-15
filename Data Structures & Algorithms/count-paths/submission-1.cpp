class Solution {
public:
    int solve(int row, int col, int m, int n, vector<vector<int>>& dp){
        //base case
        if(row < 0 || row >= m) return 0;
        if(col < 0 || col >= n) return 0;

        if(row == m-1 && col == n-1) {
            return 1; //one way of reaching
        }

        if(dp[row][col] != -1) return dp[row][col];

        int right = solve(row, col+1, m, n, dp);
        int down = solve(row+1, col, m, n, dp);

        return dp[row][col] = right + down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
        return solve(0, 0, m, n, dp);

    }
};
