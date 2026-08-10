class Solution {
public:

    void fun(vector<int> &nums, int ci, int target, vector<int> &temp, int &csum, set<vector<int>> &ans) {
        if(csum>target)return ;
        if(csum==target) {
            ans.insert(temp);
            return ;
        }

        if(ci>=nums.size())return ;

        temp.push_back(nums[ci]);
        csum+=nums[ci];
        fun(nums,ci,target,temp,csum,ans);
        csum-=nums[ci];
        temp.pop_back();

        fun(nums,ci+1,target,temp,csum,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        set<vector<int>> ans;
        int csum=0;
        fun(nums,0,target,temp,csum,ans);
        return {ans.begin(),ans.end()};
    }
};
