class Solution {
public:
    int solve(int n){
        int cnt = 0;
        while(n > 0){
            if(n & 1) cnt++;

            n = n>>1;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> ans (n+1, 0);

        for(int i = 1; i<=n; i++){
            int cnt = solve(i);
            ans[i] = cnt;
        }
        return ans;
    }
};
