class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mp; 
        vector<vector<string>> ans;

        for(auto& word: strs){
            string s2 = word;
            sort(s2.begin(), s2.end());
            
            mp[s2].push_back(word);
        }

        for(auto& w: mp){
            ans.push_back(w.second);
        }
        return ans;
    }
};
