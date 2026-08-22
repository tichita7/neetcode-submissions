class Solution {
public:
    void solve(int ind, vector<int>& nums, int target, vector<int>& curr, vector<vector<int>>& ans, int n){
        //base case
        if(ind == n){
            if(target == 0) {
                ans.push_back(curr);
            }
            return;
        }

        //condition
        if(nums[ind] <= target){
            curr.push_back(nums[ind]);
            solve(ind, nums, target - nums[ind], curr, ans, n);
            curr.pop_back(); //backtrack while returning
        }

        solve(ind+1, nums, target, curr, ans, n);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        int n = nums.size();

        solve(0, nums, target, curr, ans, n);
        return ans;
    }
};
