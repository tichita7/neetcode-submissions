class Solution {
public:
//MEMO
    int solve(int prev, int curr, vector<int>& nums, int n, vector<vector<int>>& dp){
        //base case
        if(curr == n) return 0;

        if(dp[prev+1][curr] != -1) return dp[prev+1][curr];

        //include
        int take = 0;
        int notTake = 0;

        if(prev == -1 || nums[curr] > nums[prev]){
            take = 1 + solve(curr, curr + 1, nums, n, dp);
        } 

            notTake = solve(prev, curr+1, nums, n, dp);

            return dp[prev+1][curr] = max(take, notTake);

    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        return solve(-1, 0 , nums, n, dp); //we have taken prev as -1 so we have to move one ind ahead in our dp, bcz -1 is not a valid index
    }
};
