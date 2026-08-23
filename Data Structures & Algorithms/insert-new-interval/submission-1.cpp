class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;

        int i=0;
        while(i<intervals.size()) {
            int st=intervals[i][0];
            int mx=intervals[i][1];
            while(i<intervals.size()-1 && mx>=intervals[i+1][0]) {
                mx=max(mx, intervals[i+1][1]);
                i++;
            }
            res.push_back({st,mx});
            i++;
        }
        return res;
    }
};
