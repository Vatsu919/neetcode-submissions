class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        int i=0,j=0;
        vector<int> ans;

        for(j=0;j<nums.size();j++) {
            pq.push({nums[j],j});
            if(j-i+1==k) {
                while(!pq.empty() && pq.top().second<i) {
                    pq.pop();
                }
                ans.push_back(pq.top().first);
                i++;
            }
        }
        return ans;
    }
};
