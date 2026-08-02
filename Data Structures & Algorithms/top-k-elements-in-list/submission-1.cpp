class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<vector<int>> freq(nums.size()+1);

        for(int x:nums) {
            mp[x]=mp[x]+1;
        }

        for(auto it:mp) {
            freq[it.second].push_back(it.first);
        }

        int rem=k;
        vector<int> ans;
        for(int i=nums.size();i>=0;i--) {
            for(int x:freq[i]) {
                ans.push_back(x);
                k--;
                if(k==0) {
                    return ans;
                }
            }
        }
        return ans;
    }
};
