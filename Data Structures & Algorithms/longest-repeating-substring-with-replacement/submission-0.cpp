class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        int l = 0;
        int r = 0;

        int ans = 0;

        while(r < n){
            unordered_map<char,int> mp;
            for(int i=l; i <= r; i++){
                mp[s[i]]++;
            }

            int maxi = 0;
            for(auto& it : mp){
                if(it.second > maxi){
                    maxi = it.second;
                }
            }

            if((r - l + 1) - maxi > k){
                l = l+1;
            }

            ans = max(ans, r - l + 1);

            r++;

        }

        return ans;
    }
};
