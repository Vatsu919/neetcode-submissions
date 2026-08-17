class Solution {
public:
    int mx[4]={-1,1,0,0};
    int my[4]={0,0,1,-1};

    bool isValid(int x,int y, int n,int m) {
        return x>=0 && x<n && y>=0 && y<m;
    }

    void bfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int x, int y) {
        queue<pair<int,int>> q;
        visited[x][y]=true;
        q.push({x,y});

        while(!q.empty()) {
            int ux=q.front().first;
            int uy=q.front().second;
            q.pop();

            for(int i=0;i<4;i++) {
                int vx=ux+mx[i];
                int vy=uy+my[i];

                if(isValid(vx,vy, grid.size(), grid[0].size()) && !visited[vx][vy] && grid[vx][vy]=='1') {
                    visited[vx][vy]=true;
                    q.push({vx,vy});
                }
            }
        }
        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        int ct=0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));


        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]=='1' && !visited[i][j]) {
                    bfs(grid,visited,i,j);
                    ct++;
                }
            }
        }
        return ct;
    }
};
