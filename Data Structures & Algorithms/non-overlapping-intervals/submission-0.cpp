class Solution {
public:
    static bool cmp(vector<int> v1, vector<int> v2) {
        return v1[1]<v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int noi=0;
        sort(intervals.begin(), intervals.end(), cmp);
        int li=INT_MIN;
        for(int i=0;i<intervals.size();i++) {
            if(intervals[i][0]>=li) {
                li=max(li, intervals[i][1]);
                noi++;
            }
        }
        return intervals.size()-noi;

    }
};
