class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int csum=0;
        int l=0,r=0;
        int ans=INT_MAX;

        for(r=0;r<nums.size();r++) {
            csum+=nums[r];
            while(l<=r && csum>=target) {
                ans=min(ans, r-l+1);
                csum-=nums[l];
                l++;
            }
            
        }
        return ans==INT_MAX?0:ans;
    }
};