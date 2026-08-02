class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;

        int i=0,j=0;

        int ans=0;

        for(j=0;j<s.size();j++) {
            mp[s[j]]++;
            while(i<j && mp[s[j]]>1) {
                mp[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};
