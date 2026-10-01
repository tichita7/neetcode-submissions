class Solution {
public:
    int solve(int ind, string& s, int n, vector<int>& dp){
        //base case
        if(ind >= n) return 1;

        if(s[ind] == '0') return 0;

        if(dp[ind] != -1) return dp[ind];

        int one = solve(ind+1, s, n, dp);

        int two = 0;
        if(ind + 1 < n){
            int num = (s[ind] - '0') * 10 + (s[ind+1]- '0');
            if(num >= 10 && num <= 26){
                two = solve(ind+2, s, n, dp);
            }
        }

        return dp[ind] = one + two;
        
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        
        return solve(0, s, n, dp);
    }
};
