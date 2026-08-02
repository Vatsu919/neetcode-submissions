class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)mp[nums[i]]++;

        vector<pair<int,int>> vp;

        for(auto it:mp) {
            vp.push_back({it.second, it.first});
        }

        sort(vp.begin(),vp.end());
        int i=vp.size()-1;
        vector<int> ans;
        while(k--) {
            ans.push_back(vp[i].second);
            i--;
        }
        return ans;
    }
};
