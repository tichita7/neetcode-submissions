class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);

        for(int i = 1; i<=n; i++){
            int cnt = 0;
            string s = bitset<32>(i).to_string();

            for(int j = 0; j<s.size(); j++){
                if(s[j] == '1') cnt++;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};
