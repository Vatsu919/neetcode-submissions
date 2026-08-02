class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        int j=0,l=0;
        for(j=0;j<nums.size();j++) {
            mp[nums[j]]++;
            while(j-l>k) {
                mp[nums[l]]--;
                l++;
            }
            if(mp[nums[j]]>1)return true;
        }
        return false;
    }
};