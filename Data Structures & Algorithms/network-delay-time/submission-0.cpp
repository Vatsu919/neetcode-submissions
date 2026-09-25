class Solution {
public:


    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> g(n+1);
        vector<int> dist(n+1, INT_MAX);

        for(int i=0;i<times.size();i++) {
            g[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0, k});
        dist[k]=0;

        while(!pq.empty()) {
            int ux=pq.top().second;
            int udis = pq.top().first;

            pq.pop();

            for(auto vp:g[ux]) {
                int vx = vp.first;
                int vdis = vp.second;

                if(dist[vx]>udis+vdis) {
                    dist[vx]=udis+vdis;
                    pq.push({dist[vx], vx});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++) {
            ans=max(ans,dist[i]);
        }
        return ans==INT_MAX?-1:ans;
    }
};
