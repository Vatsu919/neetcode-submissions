class Solution {
public:
    int mx[4]={0,0,1,-1};
    int my[4]={-1,1,0,0};

    bool isValid(int x,int y,int n,int m) {
        return x>=0 && x<n && y>=0 && y<m;
    }
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;

        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++) {
            if(board[i][0] == 'O'){
                q.push({i,0});
                board[i][0]='I';
            }
            if(board[i][m-1] == 'O') {
                q.push({i,m-1});
                board[i][m-1]='I';
            }
        }

        for(int j=0;j<m;j++) {
            if(board[0][j] == 'O') {
                q.push({0,j});
                board[0][j] = 'I';
            }
            if(board[n-1][j] == 'O') {
                q.push({n-1,j});
                board[n-1][j] = 'I';
            }
        }

        while(!q.empty()) {
            int ux=q.front().first;
            int uy= q.front().second;
            q.pop();

            for(int i=0;i<4;i++) {
                int vx=ux+mx[i];
                int vy=uy+my[i];

                if(isValid(vx,vy,n,m) && board[vx][vy]=='O') {
                    board[vx][vy]='I';
                    q.push({vx,vy});
                }
            }
        }


        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j]=='O') {
                    board[i][j]='X';
                }
                if(board[i][j]=='I') {
                    board[i][j]='O';
                }
            }
        }
        
    }
};
