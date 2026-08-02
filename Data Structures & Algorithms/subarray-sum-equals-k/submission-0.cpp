class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans=0;
        int cs=0;
        mp[0]=1;

        for(int i=0;i<nums.size();i++) {
            cs+=nums[i];
            ans+=(mp[cs-k]);
            mp[cs]++;
        }
        return ans;
    }
};