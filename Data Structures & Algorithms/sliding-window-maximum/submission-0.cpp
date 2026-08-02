class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        int l=0,r=0;
        vector<int> ans;

        for(r=0;r<nums.size();r++) {
            pq.push({nums[r],r});
            while(!pq.empty() && pq.top().second<l)pq.pop();
            if(r>=k-1) {
                ans.push_back(pq.top().first);
                l++;
            }
        }
        return ans;
    }
};
