class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)mp[nums[i]]++;

        vector<pair<int,int>> vp;

        for(auto it:mp) {
            vp.push_back({it.second, it.first});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i=0;i<vp.size();i++) {
            pq.push({vp[i].first, vp[i].second});
            if(pq.size()>k)pq.pop();
        }
    
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
