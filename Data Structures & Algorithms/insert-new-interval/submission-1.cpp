class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        //brute-force-> sort and make a new ans and then push back like non-interval problem but we need o(1) space
        int i = 0;
        vector<vector<int>> ans;

        while(i < n && newInterval[0] > intervals[i][1]){
            ans.push_back(intervals[i]);
            i++;
        }

        //now newInterval[0] <= interval[i][1]
        //so we check kb tk intervals[i][0] <= newInterval[1] hai
        while(i < n && intervals[i][0] <= newInterval[1] ){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        //we have correctly modified the new interval
        ans.push_back(newInterval);

        while(i < n){
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
        
    }
};
