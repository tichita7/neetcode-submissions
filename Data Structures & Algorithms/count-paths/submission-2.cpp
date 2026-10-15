class Solution {
public:
    //  Tabulation
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int r = m-1; r >=0; r--){
            for(int c = n-1; c >=0 ;c--){
                if(r == m-1 && c == n-1) {
                    dp[r][c] = 1;
                    continue; //keep moving the next iteration
                }

                int right = dp[r][c+1];
                int down = dp[r+1][c];

                dp[r][c] = right + down;
            }
        }

        return dp[0][0];
    }
};
