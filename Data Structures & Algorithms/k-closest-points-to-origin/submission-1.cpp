class Solution {
public:
    double fun(int x, int y) {
        double ans = sqrt((x)*(x)+(y)*(y));
        return ans;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, pair<int,int>>> pq;

        for(int i=0;i<points.size();i++) {
            double ans=fun(points[i][0], points[i][1]);
            pq.push({ans,{points[i][0],points[i][1]}});
            if(pq.size()>k)pq.pop();
        }

        vector<vector<int>> v;

        while(!pq.empty()) {
            pair<int,int> pt = pq.top().second;
            pq.pop();
            v.push_back({pt.first,pt.second});
        }
        return v;
    }
};
