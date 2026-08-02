class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> mp;

        for(int x:nums)mp[x]=true;
        int ans=0;
        for(int i=0;i<nums.size();i++) {
            int ct=0;
            if(nums[i]==INT_MIN || mp[nums[i]-1]!=true) {
                int nu = nums[i];
                while(nu!=INT_MAX && mp[nu]) {
                    // cout<<nu<<endl;
                    ct++;
                    nu++;
                }
                // cout<<"#########"<<endl;
                ans=max(ans,ct);
            }
        }
        return ans;
    }
};
