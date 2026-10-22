class Solution {
public:
//space-optimized tabulation
    int solve(int n, vector<int>& dp){
        if(n == 0 || n == 1) return 1;

        if(dp[n] != -1) return dp[n];

        dp[n] = solve(n-1, dp) + solve(n-2, dp);

        return dp[n];

    }
    int climbStairs(int n) {
        int prev = 1;
        int old = 1;

        for(int i = 2; i<=n; i++){
            int curr = prev + old;

            old = prev;
            prev = curr;
        }
        
        return prev;
    }
};
