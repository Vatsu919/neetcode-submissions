class Solution {
public:
    vector<int> mx={0,0,1,-1};
    vector<int> my={-1,1,0,0};
    bool isValid(int x,int y,int n, int m) {
        return x>=0 && x<n && y>=0 && y<m; 
    }
    void bfs(int sx, int sy,vector<vector<char>> &g, vector<vector<bool>> &visited) {
        queue<pair<int,int>> q;
        q.push({sx,sy});
        visited[sx][sy]=true;

        while(!q.empty()) {
            int ux=q.front().first;
            int uy=q.front().second;
            q.pop();

            for(int i=0;i<4;i++) {
                int vx=ux+mx[i];
                int vy=uy+my[i];

                if(isValid(vx,vy,g.size(), g[0].size()) && g[vx][vy]=='1' && !visited[vx][vy]) {
                    visited[vx][vy]=true;
                    q.push({vx,vy});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ct=0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]=='1' && !visited[i][j]) {
                    bfs(i,j,grid,visited);
                    ct++;
                }
            }
        }

        return ct;
    }
};
