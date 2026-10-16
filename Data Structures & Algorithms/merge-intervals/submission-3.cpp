class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int i=0;
        while(i<intervals.size()) {
            int st=i;
            int mx=intervals[i][1];

            while(i<intervals.size()-1 && mx>=intervals[i+1][0]) {
                i++;
                mx=max(mx, intervals[i][1]);
            }

            ans.push_back({intervals[st][0], mx});
            i++;
        }

        return ans;
    }
};
