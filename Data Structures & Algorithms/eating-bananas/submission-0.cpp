class Solution {
public:
    bool fun(vector<int> &piles, int h, int k) {
        int ch=0;

        for(int i=0;i<piles.size();i++) {
            ch+=piles[i]/k;
            if(piles[i]%k>0)ch++;
            if(ch>h)return false;
        }
        return ch<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int r=0;
        for(int x:piles)r=max(r,x);
        int l=1;
        int ans=r;
        while(l<=r) {
            int m=(l+r)/2;
            if(fun(piles,h,m)) {
                ans=m;
                r=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};
