class Solution {
public:
//Making the string key from the freq of characters:-> for aet, it's "1#0#0#1", like this, # is separator
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mp; 
        vector<vector<string>> ans;

        for(auto& word: strs){
            vector<int> helper(26,0);
            for(auto& ch: word){
                helper[ch - 'a']++; //for a: if a is 1, then 1th index is 1 now
            }
            
            string key = "";
            for(auto& ch: helper){
                key += to_string(ch) + "#";
            }

            mp[key].push_back(word);
        }

        for(auto& w: mp){
            ans.push_back(w.second);
        }
        return ans;
    }
};
