class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();

        vector<int> freq(128, 0);

        for(auto& ch: t){
            freq[ch]++;
        }

        int mini = 1000;

        int l = 0;
        int r = 0;
        int have = 0;
        int need = t.size();
        int st = -1;
        
        while(r < n){
            //reduce the freq
            freq[s[r]]--; //if it's required, freq will be >= 0, otherwise, < 0

            if(freq[s[r]] >= 0) have++; //required char

            //if and while have == need, we can shrink the window
            while(have == need){
                if(r - l + 1 < mini){
                    mini = r - l + 1;
                    st = l; //this is the new start
                }

                //to shrink
                freq[s[l]]++; //increase and check if it is required (> 0)
                if(freq[s[l]] > 0) have--; //we have reduced one required char
                
                l++; //move forward
            }
            r++;
        }
        return (mini == 1000)? "" : s.substr(st,mini);
    }
};
