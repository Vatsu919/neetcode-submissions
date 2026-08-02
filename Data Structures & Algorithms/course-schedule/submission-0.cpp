class Solution {
public:
    bool isCycle(int u,vector<vector<int>> &g, vector<bool> &visited, vector<bool> &recStack) {
        visited[u]=true;
        recStack[u]=true;
        bool ans =false;
        for(int v:g[u]) {
            if(visited[v] && recStack[v])return true;
            else if(!visited[v]) {
                ans=ans || isCycle(v, g, visited,recStack);
            }
        }
        recStack[u]=false;
        return ans;
    }

    bool cycleUtil(vector<vector<int>> &g) {
        int n=g.size();

        vector<bool> visited(g.size(), false);
        vector<bool> recStack(g.size(), false);

        for(int i=0;i<g.size();i++) {
            if(!visited[i] && isCycle(i,g,visited,recStack))return true;
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        for(int i=0;i<prerequisites.size();i++) {
            g[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        return !cycleUtil(g);
    }
};
