class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();

        string s1 = "";
        for(int i = 0; i<n; i++){
            if(!isalnum(s[i])) continue;
            s1 += tolower(s[i]);
        }

        string s2 = s1;
        reverse(s2.begin(), s2.end());
        cout << s1 << " " << s2;
        return (s1 == s2);
    }
};
