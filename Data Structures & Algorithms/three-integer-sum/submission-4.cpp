class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for(int i = 0; i<n; i++){

            //for duplicates
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int num1 = nums[i];
            int target = 0 - nums[i]; //target - currnum

            //2 pointer approach
            int l = i+1;
            int r = n-1;

            while(l < r){
                if(nums[l] + nums[r] < target){
                    l++;
                } else if (nums[l] + nums[r] > target){
                    r--;
                } else{
                    ans.push_back({nums[i], nums[l], nums[r]});

                    //check for duplicates
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
