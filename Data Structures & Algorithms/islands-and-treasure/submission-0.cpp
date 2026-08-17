class Solution {
public:
    int mx[4]={-1,1,0,0};
    int my[4]={0,0,1,-1};

    bool isValid(int x,int y,int n, int m) {
        return x>=0 && x<n && y>=0 && y<m;
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==0) {
                    q.push({0,{i,j}});
                }
            }
        }

        while(!q.empty()) {
            int uval=q.front().first;
            int ux=q.front().second.first;
            int uy=q.front().second.second;

            q.pop();

            for(int i=0;i<4;i++) {
                int vx=ux+mx[i];
                int vy=uy+my[i];

                if(isValid(vx,vy,n,m) && grid[vx][vy]!=0 && grid[vx][vy]!=-1 && grid[vx][vy]>uval+1) {
                    grid[vx][vy]=uval+1;
                    q.push({uval+1,{vx,vy}});
                }
            }
        }
    }
};
