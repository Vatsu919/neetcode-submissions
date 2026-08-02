class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(int i=0;i<strs.size();i++) {
            vector<int> vp(26,0);
            string s;
            for(int j=0;j<strs[i].size();j++) {
                vp[strs[i][j]-'a']++;
            }
            for(int k=0;k<26;k++) {
                s+=vp[k]+'#';
            }
            mp[s].push_back(strs[i]);
        }
        vector<vector<string>> ans;

        for(auto it:mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
