class Solution {
public:
//Using map and min heap to group elements with frequencies
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        
        unordered_map<int,int> mp;

        for(auto it: nums){
            mp[it]++;
        }

        //buckets with n+1 size
        vector<vector<int>> bucket(n+1);

        for(auto& it: mp){
            bucket[it.second].push_back(it.first);
        }
        //above looks like this: index 2 (frequency) has number 2 (2 has 2 frequency)

        //now make answer
        for(int i = bucket.size()-1; i >= 0 && ans.size() < k; i-- ){
            for(auto& num : bucket[i]){
                ans.push_back(num);

                if(ans.size() == k) break;
            }
        }

        return ans;

    }
};
