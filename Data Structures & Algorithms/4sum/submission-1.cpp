class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size()-3;i++) {
            if(i>0 && nums[i]==nums[i-1])continue;
            for(int r=nums.size()-1;r>i+2;r--) {
                if(r!=nums.size()-1 && nums[r]==nums[r+1])continue;
                int j=i+1,k=r-1;
                while(j<k) {
                    long long sum=(long long)nums[i]+(long long)nums[j]+(long long)nums[k]+(long long)nums[r];
                    if(sum==target) {
                        ans.push_back({nums[i],nums[j],nums[k],nums[r]});
                        j++;
                        k--;
                        while(j<k && nums[j]==nums[j-1]) {
                            // cout<<"j is: "<<j<<endl;
                            j++;
                        }
                    }
                    else if(sum>target)k--;
                    else j++;
                }
            }
        }
        return ans;
    }
};