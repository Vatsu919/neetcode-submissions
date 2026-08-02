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
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<pair<int,int>> vp;
        for(int i=0;i<intervals.size();i++) {
            vp.push_back({intervals[i].start, 1});
            vp.push_back({intervals[i].end, 0});
        }

        sort(vp.begin(), vp.end());
        int ct=0;
        for(int i=0;i<vp.size();i++) {
            // cout<<vp[i].first<<". "<<vp[i].second<<endl;
            if(vp[i].second==1)ct++;
            else ct--;
            if(ct>1)return false;
        }
        return true;
    }
};
