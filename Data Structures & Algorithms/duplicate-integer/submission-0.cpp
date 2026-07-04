class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;

        int n = nums.size();

        for(auto& num: nums){
            mp[num]++;
        }

        for(auto& it : mp){
            if(it.second > 1){
                return true;
                break;
            }
        }
        return false;
    }
};