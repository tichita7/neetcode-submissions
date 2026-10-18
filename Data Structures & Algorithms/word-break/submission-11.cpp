class Solution {
public:
//TABULATION
   bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> st;

        for(int i = 0; i<wordDict.size(); i++){
            st.insert(wordDict[i]);
        }

        vector<bool> dp(n+1, false);
        //if memo was from 0 to n, tabu will be from n-1 to 0
        dp[n] = true;
        
        for(int i = n-1; i>=0; i--){
            for(int j = i; j<n; j++){
                string temp = s.substr(i, j - i + 1);
                if(st.find(temp) != st.end()){
                    if(dp[j+1] == true) {
                        dp[i] = true;
                        break;
                    }
                }
            } 
        }
        
        return dp[0];
    }
};
