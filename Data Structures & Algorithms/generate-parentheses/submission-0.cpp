class Solution {
public:
    void fun(int ci, string &temp, vector<string> &ans, int n1, int n2, int n) {
        if(ci>2*n)return;
        if(ci==2*n) {
            ans.push_back(temp);
            return ;
        }

        if(n2<n1) {
            temp.push_back(')');
            fun(ci+1, temp, ans, n1, n2+1,n);
            temp.pop_back();
        }
        if(n1<n) {
            temp.push_back('(');
            fun(ci+1,temp,ans,n1+1,n2,n);
            temp.pop_back();
        }
        

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        fun(0,temp,ans,0,0,n);
        return ans;
    }
};
