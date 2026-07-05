class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n = strs.size();

        unordered_map< string, vector<string> > mp;

        for(auto& word: strs){
            string s = word;
            sort(s.begin(), s.end());
            mp[s].push_back(word); //sorted and original
        }

        for(auto& it: mp){
            ans.push_back(it.second);
        }

        return ans;
        
    }
};
