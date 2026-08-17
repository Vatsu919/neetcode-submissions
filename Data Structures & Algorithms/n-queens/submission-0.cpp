class Solution {
public:
    bool isValid(vector<string> &temp, int x,int y) {
        int n=temp[0].size();
        for(int i=0;i<n;i++) {
            if(i!=x && i<temp.size() && temp[i][y]=='Q')return false;
            if(i!=y && temp[x][i]=='Q')return false;
        }

        int cx=x,cy=y;

        while(cx>=0 && cy>=0) {
            if(cx!=x && cy!=y && temp[cx][cy]=='Q')return false;
            cx--;
            cy--;
        }
        cx=x;
        cy=y;

        while(cx>=0 && cy<temp[0].size()) {
            if(cx!=x && cy!=y && temp[cx][cy]=='Q')return false;
            cx--;
            cy++;
        }


        return true;
    }
    void fun(vector<vector<string>> &ans, int cr, int n, vector<string> &temp) {
        if(cr==n) {
            ans.push_back(temp);
            return;
        }

        string ts;
        for(int i=0;i<n;i++)ts.push_back('.');

        for(int i=0;i<n;i++) {
            ts[i]='Q';
            temp.push_back(ts);
            if(isValid(temp,cr,i)) {
                fun(ans,cr+1,n,temp);
            }
            temp.pop_back();
            ts[i]='.';
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp;
        vector<vector<string>> ans;

        fun(ans,0,n,temp);
        return ans;
    }
};
