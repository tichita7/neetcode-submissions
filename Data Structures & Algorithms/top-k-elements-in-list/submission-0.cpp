class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        unordered_map<int,int>mp;

        for(auto& num : nums){
            mp[num]++;
        }

        priority_queue< pair<int,int>, vector<pair<int,int>>> pq;

        for(auto& it: mp){
            pq.push({it.second, it.first});
        }

        for(int i = 0; i<k; i++){
            auto p = pq.top();
            pq.pop();
            ans.push_back(p.second);
        }

        return ans;
    }
};
