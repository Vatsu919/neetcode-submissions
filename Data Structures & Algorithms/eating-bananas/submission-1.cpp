class Solution {
public:
    bool canEat(vector<int> &piles, int h, int k) {
        int ch=0;
        int i=0;
        for(int i=0;i<piles.size();i++) {
            ch+=(piles[i]/k);
            if(piles[i]%k>0) {
                ch+=1;
            }
            if(ch>h)return false;
        }
        return ch<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=0;

        for(int x:piles)r=max(r,x);
        int ans=r;
        while(l<=r) {
            int m=(l+r)/2;

            if(canEat(piles,h,m)) {
                ans=m;
                r=m-1;
            }
            else {
                l=m+1;
            }
        }
        return ans;
    }
};
