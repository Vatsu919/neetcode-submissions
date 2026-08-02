class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> lp(nums.size(),1);
        vector<int> rp(nums.size(),1);

        for(int i=1;i<nums.size();i++) {
            lp[i]=nums[i-1]*lp[i-1];
        }
        for(int i=nums.size()-2;i>=0;i--) {
            rp[i]=nums[i+1]*rp[i+1];
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++) {
            ans.push_back(lp[i]*rp[i]);
        }
        return ans;
    }
};
