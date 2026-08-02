class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> lp(nums.size(),1);
        vector<int> rp(nums.size(),1);
        int cp=1;
        for(int i=0;i<nums.size();i++) {
            lp[i]=cp;
            cp*=nums[i];
        }
        cp=1;
        for(int i=nums.size()-1;i>=0;i--) {
            rp[i]=cp;
            cp*=nums[i];
        }
        vector<int> ans;

        for(int i=0;i<nums.size();i++) {
            ans.push_back(lp[i]*rp[i]);
        }
        return ans;
    }
};
