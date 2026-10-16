/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool cmp(Interval &a, Interval &b) {
        return a.end<b.end;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size()==0)return true;
        int ct=1;
        sort(intervals.begin(), intervals.end(), cmp);
        int mx=intervals[0].end;
        for(int i=1;i<intervals.size();i++) {
            if(intervals[i].start>=mx) {
                mx=intervals[i].end;
                ct++;
            }
        }

        return ct==intervals.size();
    }
};
