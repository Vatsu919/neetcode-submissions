class Solution {
public:
    void fun(vector<int> &nums, int ci, vector<int> &temp, set<vector<int>> &ans) {
        if(ci>nums.size())return ;
        if(ci==nums.size()) {
            ans.insert(temp);
            return ;
        }

        temp.push_back(nums[ci]);
        fun(nums,ci+1,temp,ans);
        temp.pop_back();
        fun(nums,ci+1,temp,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        set<vector<int>> ans;
        fun(nums, 0, temp, ans);
        return {ans.begin(), ans.end()};
    }
};
