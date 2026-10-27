class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());

        unordered_set<int> st;

        for(auto num : nums){
            st.insert(num);
        }

        for(int i = 0; i <= maxi; i++){
            if(st.find(i) == st.end()){
                return i;
            }
        }
    }
};
