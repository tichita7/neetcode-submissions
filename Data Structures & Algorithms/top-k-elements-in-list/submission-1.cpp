class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int,int> mp;

        for(auto it: nums){
            mp[it]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //bcz we need to eliminate the min first

        for(auto& it: mp){
            pq.push({it.second, it.first});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> ans;
        while(!pq.empty()){
            auto p = pq.top();
            ans.push_back(p.second);
            pq.pop();
        }

        return ans;

    }
};
