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
    static bool cmp(Interval i1, Interval i2) {
        return i1.end<i2.end;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size()==0)return true;
        sort(intervals.begin(),intervals.end(),cmp);
        int ct=1;
        int ed=intervals[0].end;

        for(int i=1;i<intervals.size();i++) {
            if(intervals[i].start>=ed) {
                ct++;
                ed=intervals[i].end;
            }
        }
        return ct==intervals.size();
    }
};
