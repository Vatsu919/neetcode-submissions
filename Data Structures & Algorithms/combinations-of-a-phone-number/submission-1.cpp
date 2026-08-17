class Solution {
public:

    void fun(int ci, unordered_map<char,string> &mp, string digits, string &temp, vector<string> &ans) {
        if(ci>=digits.size()) {
            if(temp.size()>0)
                ans.push_back(temp);
            return ;
        }

        for(char c:mp[digits[ci]]) {
            temp.push_back(c);
            fun(ci+1,mp,digits,temp,ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        string temp;
        vector<string> ans;
        fun(0,mp,digits,temp,ans);
        return ans;
    }
};
