class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cm=prices[0];
        int ans=0;
        for(int i=1;i<prices.size();i++) {
            ans=max(ans, prices[i]-cm);
            cm=min(cm, prices[i]);
        }
        return ans;
    }
};
