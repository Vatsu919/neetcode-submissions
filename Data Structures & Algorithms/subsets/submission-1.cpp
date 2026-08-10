class Solution {
public:
    void fun(vector<int> &nums, int ci, vector<int> &temp, vector<vector<int>> &ans) {
        if(ci>=nums.size()) {
            ans.push_back(temp);
            return ;
        }

        temp.push_back(nums[ci]);
        fun(nums,ci+1,temp,ans);
        temp.pop_back();

        fun(nums,ci+1,temp,ans);

        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        fun(nums,0,temp,ans);
        return {ans.begin(),ans.end()};
    }
};
