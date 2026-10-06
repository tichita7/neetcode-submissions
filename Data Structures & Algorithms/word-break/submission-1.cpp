class Solution {
public: 
    bool solve(int ind, string& s, unordered_set<string>& st,vector<int>& dp){
        //base case
        if(ind >= s.size()) return true;

        if(dp[ind] != -1) return dp[ind];
        
        for(int j = ind; j <s.size(); j++){
            if(st.find(s.substr(ind, j - ind + 1)) != st.end()){
                if(solve(j+1, s, st, dp)) return dp[ind] = 1;
            }
        }
        return dp[ind] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(n+1, -1);
        return solve(0, s, st, dp);
    }
};
