class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int l=0;
        int ans=0;
        for(int j=0;j<s.size();j++) {
            mp[s[j]]++;
            while(l<j && mp[s[j]]>1) {
                mp[s[l]]--;
                l++;
            }
            ans=max(ans,j-l+1);
        }
        return ans;
    }
};
