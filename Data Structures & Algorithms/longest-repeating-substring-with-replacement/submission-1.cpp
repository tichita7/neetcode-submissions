class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        int l = 0;
        int r = 0;

        int maxi = 0;

        while(r < n){
            vector<int> mp (26,0);

            for(int i = l; i<=r; i++){
                mp[s[i] - 'A']++;
            }

            int maxii = *max_element(mp.begin(), mp.end());
            cout << maxii;

            if((r-l+1) - maxii <= k ){
                maxi = max(maxi, r-l+1);
            } else{
                l++;
            }
            
            r++;
        }
        return maxi;
    }
};
