class Solution {
public:
    void fun(vector<int> &nums, int ci, vector<vector<int>> &ans) {
        if(ci>=nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int i=ci;i<nums.size();i++) {
            swap(nums[ci],nums[i]);
            fun(nums,ci+1,ans);
            swap(nums[ci],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp(nums);
        vector<vector<int>> ans;
        fun(temp,0,ans);
        return ans;
    }
};
