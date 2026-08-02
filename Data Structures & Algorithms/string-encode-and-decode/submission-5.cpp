class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;

        for(int i=0;i<strs.size();i++) {
            int sz = strs[i].size();
            ans+=to_string(sz) + "#";
            for(char c:strs[i])ans.push_back(c);
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int i=0;
        // cout<<s<<endl;
        while(i<s.size()) {
            string snum;
            while(i<s.size() && s[i]!='#') {
                snum.push_back(s[i]);
                i++;
            }
            i++;
            // cout<<snum<<endl;
            int num = stoi(snum);
            string temp;
            for(int k=i;k<i+num;k++) {
                temp.push_back(s[k]);
            }
            ans.push_back(temp);
            i=i+num;
        }
        return ans;
    }
};
