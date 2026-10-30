class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int ind = 1; ind <= n; ind++ ){
            for(int mind = 1; mind <= m; mind++){
                if(text1[ind-1] == text2[mind-1]){
                    dp[ind][mind] = 1 + dp[ind-1][mind-1];
                } else{
                    dp[ind][mind] = max(dp[ind-1][mind], dp[ind][mind-1]);
                }
            }
        }

        return dp[n][m];
    }
};
