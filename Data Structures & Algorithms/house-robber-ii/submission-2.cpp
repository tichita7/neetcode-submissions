class Solution {
public: 
    int solveNo(int ind, vector<int>& nums, int n, vector<int>& dp1){
        if(ind == n-1 || ind >= n){
            return 0;
        }

        if(dp1[ind] != -1) return dp1[ind];

        int take = nums[ind] + solveNo(ind+2, nums, n, dp1);
        int notTake = 0 + solveNo(ind+1, nums, n, dp1);

        return dp1[ind] = max(take, notTake);
    }

    int solveYes(int ind, vector<int>& nums, int n, vector<int>& dp){
        if(ind == n-1){
            return nums[ind]; //take
        }
        if(ind >=n){
            return 0;
        }

        if(dp[ind] != -1) return dp[ind];

        int take = nums[ind] + solveYes(ind+2, nums, n, dp);
        int notTake = 0 + solveYes(ind+1, nums, n, dp);

        return dp[ind] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1 (n+1, -1);
        vector<int> dp(n+1, -1);

        //first solve(rob first house but then cannot rob last)
        //second solve(rob second and then rob last)

        int no =  solveNo(0, nums, n, dp1);
        int yes = solveYes(1, nums, n, dp);

        return max(no, yes);

    }
};
