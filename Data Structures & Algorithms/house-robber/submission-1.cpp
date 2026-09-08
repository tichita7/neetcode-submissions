class Solution {
public:
//memoization
    int solve(int index, vector<int>& nums, vector<int>& dp){
        //base case
        if(index == 0){
            return nums[0];
        }
        if(index < 0) return 0;

        if(dp[index] != -1) return dp[index];

        //pick 
        int pick = nums[index] + solve(index - 2, nums, dp);
        int notPick = 0 + solve(index -1 , nums, dp);

        return dp[index] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n+1, -1);
        return solve(n-1, nums, dp);
    }
};
