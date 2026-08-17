class Solution {
public:
    int mx[4]={0,0,1,-1};
    int my[4]={-1,1,0,0};

    bool dfs(int cx, int cy, vector<vector<char>> &board, vector<vector<bool>> &visited, string word, int ci) {
        if(ci>=word.size()) {
            return true;
        }

        if(word[ci]!=board[cx][cy])return false;
        visited[cx][cy]=true;
        if(ci==word.size()-1)return true;

        for(int i=0;i<4;i++) {
            int rx = cx+mx[i];
            int ry = cy+my[i];

            if(isValid(rx,ry,board.size(), board[0].size()) && !visited[rx][ry]) {
                if(dfs(rx,ry,board,visited, word, ci+1))return true;
            }
        }

        visited[cx][cy]=false;
        return false;
    }

    bool dfsUtil(vector<vector<char>> &board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                if(dfs(i,j,board,visited,word,0))return true;
            }

        }
        return false;
    }

    bool isValid(int x,int y,int n, int m) {
        return x>=0 && x<n && y>=0 && y<m;
    }
    bool exist(vector<vector<char>>& board, string word) {
        return dfsUtil(board,word);
    }
};
