class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rp(9, vector<bool>(9, false));
        vector<vector<bool>> cp(9, vector<bool>(9, false));
        vector<vector<vector<bool>>> cell(3, vector<vector<bool>>(3, vector<bool>(9, false)));

        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(board[i][j]=='.')continue;
                if(rp[i][board[i][j]-'1'])return false;
                if(cp[j][board[i][j]-'1'])return false;

                int x=i/3;
                int y=j/3;
                if(cell[x][y][board[i][j]-'1'])return false;
                rp[i][board[i][j]-'1']=true;
                cp[j][board[i][j]-'1']=true;
                cell[x][y][board[i][j]-'1']=true;
            }
        }

        return true;
    }
};
