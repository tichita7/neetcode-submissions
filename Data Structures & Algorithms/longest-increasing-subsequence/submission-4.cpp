class Solution {
public:
//TABULATION
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        
        for(int i = n-1; i>=0; i--){ //curr
            for(int j = i-1; j >= -1; j--){ //prev. bcz prev is slways before curr and -1
                int take = 0;

                if(j == -1 || nums[j] < nums[i]){
                    take = 1 + dp[i+1][i+1];
                } 

                int notTake = dp[j+1][i+1];

                dp[j+1][i] = max(take, notTake);
            }
        }

        return dp[0][0];
        
    }
};
