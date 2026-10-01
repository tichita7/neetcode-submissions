class Solution {
public:

    pair<int, int> solve(int i, vector<int>& nums,
                         vector<pair<int, int>>& dp) {

        // Base case
        if (i == nums.size() - 1) {
            return {nums[i], nums[i]};
        }

        // Already calculated
        if (dp[i].first != INT_MIN) {
            return dp[i];
        }

        auto [nextMax, nextMin] = solve(i + 1, nums, dp);

        int a = nums[i];
        int b = nums[i] * nextMax;
        int c = nums[i] * nextMin;

        int currMax = max({a, b, c});
        int currMin = min({a, b, c});

        return dp[i] = {currMax, currMin};
    }

    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> dp(n, {INT_MIN, INT_MIN});

        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            auto [mx, mn] = solve(i, nums, dp);
            ans = max(ans, mx);
        }

        return ans;
    }
};