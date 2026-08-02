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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int,int>> vp;
        for(Interval it:intervals) {
            vp.push_back({it.start, 1});
            vp.push_back({it.end, 0});
        }
        sort(vp.begin(), vp.end());

        int ct=0;
        int mx=0;

        for(int i=0;i<vp.size();i++) {
            if(vp[i].second==1) {
                ct++;
                mx=max(mx,ct);
            }
            else{
                ct--;
            }
        }
        return mx;
    }
};
