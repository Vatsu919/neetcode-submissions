class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++) {
            string temp = strs[i];

            vector<int> vp(26, 0);
            for(char c:temp) {
                vp[c-'a']++;
            }

            string hs;
            for(int i=0;i<26;i++) {
                hs+=vp[i]+'#';
            }
            mp[hs].push_back(strs[i]);

        }

        vector<vector<string>> ans;

        for(auto it:mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
