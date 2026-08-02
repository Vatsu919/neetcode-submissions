class Solution {
public:

    bool isValid(int x,int y, vector<vector<char>> &board, vector<vector<bool>> &rw, vector<vector<bool>> &col, vector<vector<vector<bool>>> &cel) {
        return !rw[x][board[x][y]] && !col[y][board[x][y]] && !cel[x/3][y/3][board[x][y]];
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<vector<bool>>> cel(9, vector<vector<bool>>(9, vector<bool>(9, false)));

        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(board[i][j]!='.') {
                    if(!isValid(i, j, board, row, col ,cel))return false;
                    row[i][board[i][j]]=true;
                    col[j][board[i][j]]=true;
                    cel[i/3][j/3][board[i][j]]=true;
                }
            }
        }

        return true;
    }
};
