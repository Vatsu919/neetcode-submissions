class Solution {
public:

    void dfs(int u, vector<vector<int>> &g, vector<bool> &visited, stack<int> &st) {
        visited[u]=true;

        for(int v: g[u]) {
            if(!visited[v]) {
                dfs(v,g,visited,st);
            }
        }
        st.push(u);
    }

    bool isCycle(int u, vector<vector<int>> &g, vector<bool> &visited, vector<bool> &recStack) {
        visited[u]=true;
        recStack[u]=true;

        bool ans=false;

        for(int v:g[u]) {
            if(recStack[v])return true;
            if(!visited[v]) {
                ans = ans || isCycle(v,g,visited,recStack);
            }
        }

        recStack[u]=false;
        return ans;
    }

    bool fun(vector<vector<int>> &g, stack<int> &st) {
        vector<bool> visited(g.size());
        vector<bool> recStack(g.size());
        vector<bool> visited1(g.size());
        
        for(int i=0;i<g.size();i++) {
            if(isCycle(i, g, visited, recStack))return false;
        }

        for(int i=0;i<g.size();i++) {
            dfs(i,g,visited1,st);
        }
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int> ans;
        stack<int> st;

        vector<vector<int>> g(numCourses);

        for(int i=0;i<pre.size();i++) {
            g[pre[i][1]].push_back(pre[i][0]);
        }
        if(!fun(g,st))return ans;

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
