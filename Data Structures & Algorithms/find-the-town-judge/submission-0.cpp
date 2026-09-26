class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> g(n+1);

        vector<bool> isThere(n+1, false);

        for(int i=0;i<trust.size();i++) {
            g[trust[i][1]].push_back(trust[i][0]);
            isThere[trust[i][0]]=true;
        }

        for(int i=1;i<=n;i++) {
            if(!isThere[i] && g[i].size()==n-1)return i;
        }
        return -1;
    }
};