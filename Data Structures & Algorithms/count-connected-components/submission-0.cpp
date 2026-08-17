class Solution {
public:
    void bfs(vector<vector<int>> &g, int n, int u, vector<bool> &visited) {
        
        queue<int> q;

        visited[u]=true;
        q.push(u);

        while(!q.empty()) {
            int x=q.front();
            q.pop();

            for(int v:g[x]) {
                if(!visited[v]) {
                    visited[v]=true;
                    q.push(v);
                }
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n,false);
        vector<vector<int>> g(n);

        for(int i=0;i<edges.size();i++) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        int ans=0;

        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                ans++;
                bfs(g,n,i,visited);
            }
        }
        return ans;
    }
};
