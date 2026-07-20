class Solution {
public:
//we have to combine the strings in the list into 1 string, so we will use # but in a special way
    string s = "";
    string encode(vector<string>& strs) {
        for(auto& word: strs){
            s += to_string(word.size()) + "#" + word;
        }
        return s;
    }
    vector<string> ans;
    vector<string> decode(string s) {
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
