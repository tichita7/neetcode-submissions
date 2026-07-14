class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;

        if(s.size() == 1) return true;

        while(l < r){
            while(l < r && !isalnum(s[l])){
                l++;
            }
            while(r > l && !isalnum(s[r])){
                r--;
            }

            if(tolower(s[l]) != tolower(s[r])){
                return false;
            }
            l++;
            r--;
        }
    return true;
    }
};
