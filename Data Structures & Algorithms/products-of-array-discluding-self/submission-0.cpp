class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> lmul(nums.size(), 1);
        vector<int> rmul(nums.size(), 1);
        int prod=1;
        for(int i=0;i<nums.size();i++) {
            lmul[i]=prod;
            prod*=nums[i];
        }
        prod=1;
        for(int i=nums.size()-1;i>=0;i--) {
            rmul[i]=prod;
            prod*=nums[i];
        }

        vector<int> ans;
        for(int i=0;i<nums.size();i++) {
            ans.push_back(lmul[i]*rmul[i]);
        }
        return ans;
    }
};
