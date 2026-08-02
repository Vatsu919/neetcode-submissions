class Solution {
public:
    bool checkValid(vector<vector<char>> &board, int x,int y) {
        int row=(x/3)*3;
        int col=(y/3)*3;

        char t=board[x][y];
        if(t=='.')return true;
        for(int i=0;i<9;i++) {
            if(i!=x && board[i][y]==t)return false;
        }
        for(int j=0;j<9;j++) {
            if(j!=y && board[x][j]==t)return false;
        }

        for(int i=row;i<row+3;i++) {
            for(int j=col;j<col+3;j++) {
                if(i!=x && j!=y && board[i][j]==t)return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(!checkValid(board,i,j))return false;
            }
        }
        return true;
    }
};
