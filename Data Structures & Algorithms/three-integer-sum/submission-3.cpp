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
            int num2 = 0 - nums[i]; //target - currnum

            unordered_set<int> st;

            for(int j = i+1; j<n; j++){
                int needed = num2 - nums[j];
                if(st.find(needed) != st.end()){
                    ans.push_back({num1, nums[j], needed});
                    // we found the triplet (at nums[j] == 2, next j is also 2, so we skip it beforehand)
                    while(j+1 < n && nums[j] == nums[j+1]) j++;
                }


                //if not present or present
                st.insert(nums[j]);
            }
        }

        return ans;
        
    }
};
