class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        
        int l = 0;
        int r = 0;

        int needed = t.size();
        int have = 0; //required char
        int st = -1;
        int mini = 1000;

        vector<int> mp(128,0);

        for(auto& ch: t){
            mp[ch]++;
        }

        while(r < n){
            mp[s[r]]--; 

            if(mp[s[r]] >= 0) have++; //required char

            while(have == needed){ //jab tk req. char t k size ke equal hai, window valid hai
                if(r - l + 1 < mini){
                    mini = r - l + 1;
                    st = l;
                }
                
                mp[s[l]]++;

                if(mp[s[l]] <= 0){
                   l++;
                } else{
                    have--;
                    l++;
                }
                
            }
            r++;
        }
        return (mini == 1000) ? "" : s.substr(st, mini);

    }
};
