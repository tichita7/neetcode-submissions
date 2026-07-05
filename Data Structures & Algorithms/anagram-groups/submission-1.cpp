class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(auto& word: strs){
            vector<int> freq(26, 0);
            for(char c : word)
                freq[c-'a']++;

            string key = "";
            for(int i = 0; i < 26; i++)
                key += to_string(freq[i]) + ",";

            mp[key].push_back(word);
        }

        vector<vector<string>> ans;
        for(auto& it: mp) {
            ans.push_back(it.second);
        }

        return ans; 
    }
};
