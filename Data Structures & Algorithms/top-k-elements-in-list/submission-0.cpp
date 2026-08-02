class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto x:nums)mp[x]++;
        vector<vector<int>> v(nums.size()+1);

        for(auto it:mp) {
            v[it.second].push_back(it.first);
        }
        int i=nums.size()-1;
        vector<int> ans;
        for(int i=nums.size();i>=0;i--) {
            for(auto x:v[i]) {
                ans.push_back(x);
                if(ans.size()==k)return ans;
            }
        }
        return ans;

    }
};
