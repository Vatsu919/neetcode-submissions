class Solution {
public:

    int characterReplacement(string s, int k) {
        int l=0,r=0,mx=0;
        unordered_map<char,int> mp;
        int ans=0;

        for(r=0;r<s.size();r++) {
            mp[s[r]]++;
            mx=max(mx,mp[s[r]]);
            while(l<r && (r-l+1)-mx>k) {
                mp[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
