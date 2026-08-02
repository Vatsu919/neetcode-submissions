class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ce=prices[0];
        int ans=0;
        for(int i=1;i<prices.size();i++) {
            if(prices[i]>ce) {
                ans+=prices[i]-ce;
                ce=prices[i];
            }
            else {
                ce=prices[i];
            }
            
        }
        return ans;
    }
};