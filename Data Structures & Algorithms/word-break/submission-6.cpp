class Solution {
public:
    bool solve(int ind, string& s, unordered_set<string>& st, vector<int>& dp)
{
    //base case
    if(ind == s.size()) return true;

    if(dp[ind] != -1) return dp[ind];

    for(int i = ind; i<s.size(); i++){
        string temp = s.substr(ind, i - ind + 1);
        if(st.find(temp) != st.end()){
            if(solve(i+1, s, st, dp)) return dp[ind] =true;
        }
    }
    return dp[ind] = false;

}    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> st;
        vector<int> dp(n, -1);

        for(int i = 0; i<wordDict.size(); i++){
            st.insert(wordDict[i]);
        }

        return solve(0, s, st, dp);
    }
};
