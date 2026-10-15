class Solution {
public:
    int solve(int ind, int mind, string& text1, string& text2, vector<vector<int>>& dp){
        //base case
        if(ind < 0 || mind < 0) return 0;

        if(dp[ind][mind] != -1) return dp[ind][mind];

        if(text1[ind] == text2[mind]){
            return dp[ind][mind] = 1 + solve(ind-1, mind-1, text1, text2, dp);
        } else{
            return dp[ind][mind] = max(solve(ind-1, mind, text1, text2, dp), solve(ind, mind-1, text1, text2, dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(n-1, m-1, text1, text2, dp);
    }
};
