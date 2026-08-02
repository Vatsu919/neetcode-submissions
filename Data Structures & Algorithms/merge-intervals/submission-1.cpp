class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i=0;
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        while(i<intervals.size()) {
            int st=intervals[i][0];
            int ed=intervals[i][1];
            while(i<intervals.size() && intervals[i][0]<=ed) {
                ed=max(ed,intervals[i][1]);
                i++;
            }
            ans.push_back({st,ed});
        }
        return ans;
    }
};
