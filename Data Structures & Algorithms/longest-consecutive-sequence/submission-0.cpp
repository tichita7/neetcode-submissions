class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st;
        vector<int> begin;

        for(auto& num: nums ){
            st.insert(num);
        }

        //we r using set for o(1) lookups

        //form a vector of begin points
        for(auto& it: st){
            int num = it;
            if(st.find(it-1) == st.end()){
                begin.push_back(it);
            }
        }

        int maxi = 0;
        //now look for the actual longest sequence
        for(auto& num: begin){
            int k = num;
            int cnt = 1;
            
            while(st.find(k+1) != st.end()){
                cnt++;
                k = k+1;
            }
            
            maxi = max(maxi, cnt);
            
        }

        return maxi;
    }
};
