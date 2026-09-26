class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int, int> edgeCount;
        vector<vector<int>> g(n);
        queue<int> q;

        if(n==1)return {0};

        for(int i=0;i<edges.size();i++) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i=0;i<n;i++) {
            if(g[i].size()==1) {
                q.push(i);
            }
            edgeCount[i]=g[i].size();
        }

        while(!q.empty()) {
            int s=q.size();
            if(n<=2) {
                vector<int> temp;
                while(!q.empty()) {
                    temp.push_back(q.front());
                    q.pop();
                }
                return temp;
            }
            while(s--) {
                int u=q.front();
                q.pop();
                n--;

                for(int v:g[u]) {
                    edgeCount[v]--;
                    if(edgeCount[v]==1) {
                        q.push(v);
                    }
                }
            }
        }
        return {};
    }
};