class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int i=0;
        while(i<intervals.size()) {
            int st=intervals[i][0];
            int ed=intervals[i][1];
            while(i<intervals.size()-1 && ed>=intervals[i+1][0]) {
                ed=max(ed,intervals[i+1][1]);
                i++;
            }
            ans.push_back({st,ed});
            i++;
        }
        return ans;
    }
};
