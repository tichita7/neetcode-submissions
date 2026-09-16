class Solution {
public:
    int solve(int left, int right, string& s){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }

        return right - left - 1;

    }
    string longestPalindrome(string s) {
        //centering around algo
        int n = s.size();
        int maxi = 1;
        int start = -1;

        for(int i = 0; i<n; i++){
            int odd = solve(i,i, s);
            int even = solve(i, i+1, s);

            int best = max(even, odd);

            if(best >= maxi){
                maxi = best;
                start = i - (best-1)/2;
            }
        }
        return s.substr(start, maxi);
    }
};
