class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        int i=0;
        vector<vector<int>> ans;
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
