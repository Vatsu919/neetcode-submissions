class Solution {
public:
    int mx[4]={0,0,1,-1};
    int my[4]={-1,1,0,0};

    bool isValid(int x,int y, int n,int m) {
        return x>=0 && x<n && y>=0 && y<m;
    }
    int bfs(vector<vector<int>> &grid, int x,int y, vector<vector<bool>> &visited) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>> q;
        visited[x][y]=1;
        q.push({x,y});
        int ans=1;

        while(!q.empty()) {
            int ux=q.front().first;
            int uy=q.front().second;
            q.pop();

            for(int i=0;i<4;i++) {
                int vx=ux+mx[i];
                int vy=uy+my[i];
                if(isValid(vx,vy,n,m) && !visited[vx][vy] && grid[vx][vy]==1) {
                    visited[vx][vy]=1;
                    ans++;
                    q.push({vx,vy});
                }
            }
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(),false));

        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(!visited[i][j] && grid[i][j]==1) {
                    ans=max(ans, bfs(grid,i,j,visited));
                }
            }
        }

        return ans;
    }
};
