class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mip=1;
        int maxp=1;

        int res=INT_MIN;
        for(int x:nums)res=max(res,x);

        for(int i=0;i<nums.size();i++) {
            int cp = maxp*nums[i];

            maxp = max(cp, max(mip*nums[i], nums[i]));
            mip = min(cp, min(mip*nums[i], nums[i]));
            res=max(res, maxp);
        }
        return res;
    }
};
