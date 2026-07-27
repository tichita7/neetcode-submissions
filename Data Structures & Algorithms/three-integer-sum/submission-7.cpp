class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i = 0; i<n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int num1 = nums[i];
            int target = 0 - num1;

            int l = i+1;
            int r = n-1;

            while(l < r){
                if(nums[l] + nums[r] > target){
                    r--;
                } else if(nums[l] + nums[r] < target){
                    l++;
                } else{
                    ans.push_back({num1, nums[l], nums[r]});

                    while(l < r && nums[l] == nums[l+1]) l++;
                    while(r > l && nums[r] == nums[r-1]) r--;

                    l++;
                    r--;
                }
                
            }
        }
        return ans;
    }
};
