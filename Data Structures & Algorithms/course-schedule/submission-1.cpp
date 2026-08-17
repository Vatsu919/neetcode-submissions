class Solution {
public:

    bool dfs(int u, vector<vector<int>> &g, vector<bool> &visited, vector<bool> &recStack) {
        visited[u]=true;
        recStack[u]=true;
        bool ans=false;
        for(int v:g[u]) {
            if(recStack[v])return true;
            if(!visited[v]) {
                ans=ans || dfs(v,g,visited,recStack);
            }
        }

        recStack[u]=false;
        return ans;
    }

    bool dfsUtil(vector<vector<int>> &g) {
        vector<bool> visited(g.size(),false);
        vector<bool> recStack(g.size(), false);

        for(int i=0;i<g.size();i++) {
            if(dfs(i,g,visited, recStack))return true;
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> g(numCourses);


        for(int i=0;i<pre.size();i++) {
            g[pre[i][1]].push_back(pre[i][0]);
        }

        return !dfsUtil(g);
    }
};
