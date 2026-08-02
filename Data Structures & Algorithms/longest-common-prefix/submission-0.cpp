class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int mi = strs[0].size();

        for(int i=0;i<strs.size();i++)mi=min(mi,(int)strs[i].size());

        for(int i=0;i<mi;i++) {
            char c=strs[0][i];
            for(int j=0;j<strs.size();j++) {
                if(strs[j][i]!=c)return ans;
            }
            ans.push_back(c);
        }
        return ans;
    }
};