class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;

        for(int i = 0; i <= n; i++){
            int cnt = 0;

            int j = i;
            while( j> 0){
                if(j & 1) cnt++;
                j = j >> 1;
            }

            ans.push_back(cnt);
        }

        return ans;

    }
};
