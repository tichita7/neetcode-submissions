class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        string s = bitset<32>(n).to_string();

        for(int i = 0; i<s.size(); i++){
            if(s[i] == '1') cnt++;
        }
        return cnt;

    }
};
