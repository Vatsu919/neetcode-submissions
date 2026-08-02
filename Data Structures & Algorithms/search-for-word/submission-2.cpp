class Solution {
public:
    int mx[4]={-1,1,0,0};
    int my[4]={0,0,1,-1};

    bool isValid(int x,int y,int n,int m) {
        return x>=0 && x<n && y>=0 && y<m;
    }
    bool dfs(vector<vector<char>> &g, vector<vector<bool>> &visited, string word,int ux, int uy, int ci) {
        visited[ux][uy]=true;
        bool ans=false;
        if(ci==word.size())return true;
        for(int i=0;i<4;i++) {
            int vx=ux+mx[i];
            int vy=uy+my[i];
            if(isValid(vx,vy,g.size(),g[0].size()) && !visited[vx][vy] && g[vx][vy]==word[ci]) {
                ans = ans || dfs(g,visited, word, vx,vy,ci+1);
            }
        }
        visited[ux][uy]=false;
        /*
            A B C E
            S F E S
            A D E E      
        */
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        
        

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j]==word[0]) {
                    vector<vector<bool>> visited(n, vector<bool>(m , false));
                    if(dfs(board,visited,word,i, j, 1))return true;
                }
            }
        }
        return false;
        
    }
};
