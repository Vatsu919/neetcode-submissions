class Solution {
public:
    int trap(vector<int>& h) {
        vector<int> lp(h.size(),0);
        vector<int> rp(h.size(),0);
        int cm=h[0];
        for(int i=1;i<h.size();i++) {
            lp[i]=cm;
            cm=max(cm,h[i]);
        }
        cm=h[h.size()-1];
        for(int i=h.size()-1;i>=0;i--) {
            rp[i]=cm;
            cm=max(cm,h[i]);
        }
        int ans=0;
        for(int i=0;i<h.size();i++) {
            int cans = max(min(lp[i],rp[i])-h[i], 0);
            ans+=cans;
        }
        return ans;
    }
};
