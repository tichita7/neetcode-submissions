class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int l = 0;
        int r = 0;

        unordered_map<char,int> mp;

        int maxi = 0;

        while(r < n){
            if(mp.find(s[r]) != mp.end() && mp[s[r]] >= l ){
                l = mp[s[r]] + 1;
            }

            mp[s[r]] = r;
            int len = r - l + 1;
            cout << l << r << len << endl;
            maxi = max(maxi, len);
            r++;
        }
        return maxi;
    }
};
