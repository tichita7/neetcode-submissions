class Solution {
public:
//we have to combine the strings in the list into 1 string, so we will use # but in a special way
    
    string encode(vector<string>& strs) {
        string s = "";
        for(auto& word: strs){
            s += to_string(word.size()) + "#" + word;
        }
        return s;
    }
    
    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while(i < s.size()){
            int j = i;

            while(s[j] != '#'){
                j++; //skip the numbers
            }

            int len = stoi(s.substr(i, j-i));

            ans.push_back(s.substr(j+1, len));
            i = j + 1 + len;
        }
        return ans;
    }
};
