class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;
        int x = (int) n;
        while(x>0) {
            ans += (x&1);
            x=x>>1;
        }
        return ans;
    }
};
