class Solution {
public:
    int sol(vector<int>& prices, vector<vector<int>> &dp, int ci, bool canBuy) {
        if(ci>=prices.size())return 0;
        if(dp[ci][canBuy]!=-1)return dp[ci][canBuy];

        if(canBuy) {
            int buy = sol(prices,dp,ci+1,!canBuy) - prices[ci];
            int cooldown = sol(prices,dp,ci+1,canBuy);
            dp[ci][canBuy] = max(buy,cooldown);
        } 
        else {
            int sell = sol(prices,dp, ci+2, !canBuy) + prices[ci];
            int cooldown = sol(prices,dp,ci+1,canBuy);
            dp[ci][canBuy] = max(sell, cooldown);
        }
        return dp[ci][canBuy];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return sol(prices, dp, 0, true);
    }
};
