class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;

        for(int i=0;i<nums.size()-2;i++) {
            int l=i+1;
            int r=nums.size()-1;
            while(l<r) {
                int sum = nums[i]+nums[l]+nums[r];
                if(sum==0) {
                    ans.insert({nums[i],nums[l], nums[r]});
                    l++;
                    r--;
                }
                else if(sum>0)r--;
                else l++;
            }
        }

        return {ans.begin(), ans.end()};
    }
};
