class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int ans= 0;
        
        for(int i = 1; i<n; i++){
            int p = prices[i] - mini;

            if(prices[i] < mini){
                mini = prices[i];
            }
            ans = max(ans, p);
        }

        return ans;
    }
};
