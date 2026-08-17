class Solution {
public:
    int mx[4]={-1,1,0,0};
    int my[4]={0,0,1,-1};

    bool isValid(int x,int y,int n, int m) {
        return x>=0 && x<n && y>=0 && y<m;
    } 
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n=h.size();
        int m=h[0].size();


        vector<vector<bool>> pac(n, vector<bool>(m ,false));
        vector<vector<bool>> atl(n, vector<bool>(m ,false));

        queue<pair<int,int>> pacq;
        queue<pair<int,int>> atq;

        for(int i=0;i<n;i++) {
            pac[i][0]=true;
            pacq.push({i,0});

            atl[i][m-1]=true;
            atq.push({i,m-1});
        }

        for(int j=0;j<m;j++) {
            pac[0][j]=true;
            pacq.push({0,j});

            atl[n-1][j]=true;
            atq.push({n-1,j});
        }


        while(!pacq.empty()) {
            int ux=pacq.front().first;
            int uy=pacq.front().second;

            pacq.pop();

            for(int i=0;i<4;i++) {
                int vx=ux+mx[i];
                int vy=uy+my[i];

                if(isValid(vx,vy,n,m) && !pac[vx][vy] && h[vx][vy]>=h[ux][uy]) {
                    pac[vx][vy]=true;
                    pacq.push({vx,vy});
                }
            }
        }

        while(!atq.empty()) {
            int ux=atq.front().first;
            int uy=atq.front().second;
            atq.pop();

            for(int i=0;i<4;i++) {
                int vx=ux+mx[i];
                int vy=uy+my[i];

                if(isValid(vx,vy,n,m) && !atl[vx][vy] && h[vx][vy]>=h[ux][uy]) {
                    atl[vx][vy]=true;
                    atq.push({vx,vy});
                }
            }
        }

        vector<vector<int>> ans;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(pac[i][j] && atl[i][j])ans.push_back({i,j});
            }
        }
        return ans;

        
    }
};
