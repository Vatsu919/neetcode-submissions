class Solution {
public:
    bool isValid(int x, int y, vector<vector<char>> &board) {
       

        for(int i=0;i<9;i++) {
            if(i!=x && board[i][y]==board[x][y])return false;
            if(i!=y && board[x][i]==board[x][y])return false;
        }
        int cx = x/3;
        int cy = y/3;

        int sx=cx*3;
        int sy=cy*3;

        for(int i=sx;i<sx+3;i++) {
            for(int j=sy;j<sy+3;j++) {
                if(i!=x && j!=y && board[i][j]==board[x][y])return false; 
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                if(board[i][j]=='.')continue;
                if(!isValid(i,j,board))return false;
            }
        }
        return true;
    }
};
