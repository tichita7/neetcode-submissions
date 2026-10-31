class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int cnt = 0;

        sort(intervals.begin(), intervals.end()); //very imp

        //for comparing
        int st = intervals[0][0];
        int end = intervals[0][1];

        for(int i = 1; i<n; i++){
            if(intervals[i][0] < end){
                cnt++;
                end = min(end, intervals[i][1]); //keep the smaller ending to move forward
            } else {
                st = intervals[i][0];
                end = intervals[i][1];
            }
        }
        return cnt;
    }
};
