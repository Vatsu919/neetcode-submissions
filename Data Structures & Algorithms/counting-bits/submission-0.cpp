class Solution {
public:
    int ctbits(int n) {
        int ans=0;
        while(n>0) {
            ans+=(n&1);
            n=n>>1;
        }
        return ans;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++) {
            ans.push_back(ctbits(i));
        }
        return ans;
    }
};
