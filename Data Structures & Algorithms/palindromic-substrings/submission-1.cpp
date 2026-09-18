class Solution {
public:
    int solve(int left, int right, string& s, int cnt){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
            cnt++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int n = s.size();

        int maxi = 0;

        for(int i = 0; i<n; i++){
            int odd = solve(i, i, s, 0);
            int even = solve(i, i+1, s, 0);

            int total = odd + even;
            maxi += total;
        }

        return maxi;

    }
};
