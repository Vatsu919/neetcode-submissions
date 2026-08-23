class Solution {
public:
    static bool cmp(vector<int> &v1, vector<int> &v2) {
        return v1[1] < v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int ct=1;
        int ed=intervals[0][1];

        for(int i=1;i<intervals.size();i++) {
            if(intervals[i][0]>=ed) {
                ct++;
                ed=intervals[i][1];
            }
        }
        return intervals.size()-ct;
    }
};