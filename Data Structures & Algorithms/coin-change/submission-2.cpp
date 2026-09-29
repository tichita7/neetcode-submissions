class Solution {
public:
//memoization
    int solve(int ind, vector<int>& coins, int amount, vector<vector<int>>& dp){
        //base case
        if(amount == 0){
            return 0; //need no more coins
        }

        if(ind >= coins.size()){
            return 1e9;
        }

        if(dp[ind][amount] != -1) return dp[ind][amount];

        int take = INT_MAX;
        if(coins[ind] <= amount){
            take =  1 + solve(ind, coins, amount - coins[ind], dp);
        }

        int notTake = solve(ind+1, coins, amount, dp);

        return dp[ind][amount] = min(take, notTake);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        //find min choices
        vector<vector<int>> dp(n+1, vector<int>(amount + 1, -1));

        int ans = solve(0, coins, amount, dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};
