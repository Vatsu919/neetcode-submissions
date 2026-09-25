class Solution {
public:
    int mx[4]={0,0,1,-1};
    int my[4]={-1,1,0,0};
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int ux=-1, uy=-1;
        for(int i=0;i<n;i++) {
            bool found=false;
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1) {
                    ux=i;
                    uy=j;
                    found = true;
                    break;
                }
            }
            if(found)break;
        }

        visited[ux][uy]=1;
        int perimeter=0;

        queue<pair<int,int>> q;
        q.push({ux,uy});

        while(!q.empty()) {
            int sx=q.front().first;
            int sy=q.front().second;
            q.pop();

            for(int i=0;i<4;i++) {
                int vx=sx+mx[i];
                int vy=sy+my[i];

                if(vx<0 || vy<0 || vx>=n || vy>=m || grid[vx][vy]==0) {
                    perimeter++;
                }
                else if(!visited[vx][vy]) {
                    visited[vx][vy]=1;
                    q.push({vx,vy});
                }
            }
        }

        return perimeter;
    }
};