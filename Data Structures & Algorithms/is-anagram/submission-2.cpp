class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n != m) return false;

        unordered_map<char, int> s_mp;
        unordered_map<char, int> t_mp;

        for(auto& ch: s){
            s_mp[ch]++;
        }

        for(auto& ch: t){
            t_mp[ch]++;
        }

        if(s_mp == t_mp) return true;

        return false;
    }
};
