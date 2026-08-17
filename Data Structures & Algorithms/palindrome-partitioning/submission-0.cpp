class Solution {
public:
    void fun(string s, int si, int ci, vector<string> &temp, vector<vector<string>> &ans) {
        if(ci>=s.size()) {
            if(temp.size()>0 && ci==s.size() && si==s.size())ans.push_back(temp);
            return ;
        }
        string ts = s.substr(si, ci-si+1);
        string tsr = ts;
        reverse(tsr.begin(),tsr.end());

        if(ts==tsr) {
            temp.push_back(ts);
            fun(s,ci+1,ci+1, temp,ans);
            temp.pop_back();
        }
        fun(s,si,ci+1,temp,ans);
        
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;

        fun(s,0,0,temp,ans);
        return ans;
    }
};
