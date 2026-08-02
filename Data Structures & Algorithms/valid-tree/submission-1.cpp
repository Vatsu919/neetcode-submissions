class Solution {
public:
    bool isCycle(int u, vector<vector<int>> &g, vector<bool> &visited, int parent) {
        visited[u]=true;
        bool ans=false;
        for(int v:g[u]) {
            if(visited[v] && parent!=v)return true;
            else if(!visited[v]) {
                ans = ans || isCycle(v, g, visited, u);
            }
        }
        return ans;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> g(n);

        for(int i=0;i<edges.size();i++) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }


        bool ans = !isCycle(0, g, visited, -1);
        for(int i=0;i<g.size();i++) {
            if(!visited[i])return false;
        }
        return ans;
    }
};
