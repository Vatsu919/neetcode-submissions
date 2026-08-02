class Solution {
public:
    static bool cmp(int n1,int n2) {
        return n1>n2;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> vp;
        for(int i=0;i<position.size();i++) {
            vp.push_back({position[i], speed[i]});
        }
        sort(vp.begin(), vp.end());

        stack<double> s;
        for(int i=vp.size()-1;i>=0;i--) {
            double ti = (double)((double)(target-vp[i].first)/(double)vp[i].second);
            // cout<<i<<". "<<ti<<endl;
            if(!s.empty()) {
                // double ti = (double)((double)(target-vp[i].first)/(double)vp[i].second);
                // cout<<"st is: "<<s.top()<<" for i: "<<i<<endl;
                if(ti>s.top()) {
                    s.push(ti);
                }
            }
            else {
                s.push(ti);
            }
        }
        return s.size();
    }
};
