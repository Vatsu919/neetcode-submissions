class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> mp;
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        for(string x:wordDict)mp[x]=true;
        for(int i=0;i<s.size();i++) {
            for(int j=i;j>=0;j--) {
                string tmp = s.substr(j, i-j+1);
                if(mp.find(tmp)!=mp.end()) {
                    dp[i+1] = dp[i+1] || (dp[j]);
                }
            }
        }
        return dp[s.size()];
    }
};
