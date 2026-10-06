/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        
        int cnt = 0;
        int maxi = 0;

        vector<int> st, end;

        for(auto& i: intervals){
            st.push_back(i.start);
            end.push_back(i.end);
        }

        //sort both
        sort(st.begin(), st.end());
        sort(end.begin(), end.end());

        int s = 0;
        int e = 0;

        while(s < n){
            if(st[s] < end[e]){
                cnt++;
                s++;
            } else{
                cnt--;
                e++;
            }
            maxi = max(maxi, cnt);
        }

        return maxi;
    }
};
