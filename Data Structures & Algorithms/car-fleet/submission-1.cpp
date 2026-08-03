class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> st;

        vector<pair<int,int>> vp;

        for(int i=0;i<position.size();i++) {
            vp.push_back({position[i],speed[i]});
        }

        sort(vp.rbegin(), vp.rend());

        for(int i=0;i<vp.size();i++) {
            double tm = (double)(target-vp[i].first)/(double)vp[i].second;

            if(!st.empty()) {
                if(tm>st.top())st.push(tm);
            }
            else st.push(tm);
        }
        return st.size();
    }
};
