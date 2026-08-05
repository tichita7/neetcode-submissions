class Solution {
public:
    void solve(int ind, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans, int target){
        if(ind == nums.size()){
            if(target == 0){
                ans.push_back(curr);
            }
            return;
        }

        if(nums[ind] <= target){
            curr.push_back(nums[ind]);
            solve(ind, nums, curr, ans, target - nums[ind]);
            curr.pop_back();
        }

        solve(ind+1, nums, curr, ans, target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        vector<vector<int>> ans;

        solve(0, nums, curr, ans, target);
        return ans;
    }
};
