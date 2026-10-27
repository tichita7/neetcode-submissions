class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        unordered_set<int> st;

        for(auto num : nums){
            st.insert(num);
        }

        for(int i = 0; i <= nums[n-1]; i++){
            if(st.find(i) == st.end()){
                return i;
            }
        }
    }
};
