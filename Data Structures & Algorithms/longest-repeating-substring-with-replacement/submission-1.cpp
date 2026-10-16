class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int i=0,j=0;
        int mx=0;
        int ans=0;

        for(j=0;j<s.size();j++) {
            mp[s[j]]++;
            mx=max(mx, mp[s[j]]);

            while(i<j && (j-i+1)-mx>k) {
                mp[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};
