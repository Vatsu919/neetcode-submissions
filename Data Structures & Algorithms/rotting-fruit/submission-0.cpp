class Solution {
public:
    int mx[4]={0,0,1,-1};
    int my[4]={-1,1,0,0};

    bool isValid(int x,int y, int n, int m) {
        return x>=0 && x<n && y>=0 && y<m;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;

        int ans=0;
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==2) {
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()) {
            int s=q.size();

            while(s--) {
                int ux=q.front().first;
                int uy=q.front().second;
                q.pop();

                for(int i=0;i<4;i++) {
                    int vx=ux+mx[i];
                    int vy=uy+my[i];

                    if(isValid(vx,vy,n,m) && grid[vx][vy]==1) {
                        grid[vx][vy]=2;
                        q.push({vx,vy});
                    }
                }
            }
            ans++;
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1)return -1;
            }
        }



        return ans==0?ans:ans-1;
    }
};
