class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> vp(26,0);
        vector<int> vp1(26,0);

        for(int i=0;i<s.size();i++)vp[s[i]-'a']++;
        for(int i=0;i<t.size();i++)vp1[t[i]-'a']++;

        for(int i=0;i<26;i++) {
            if(vp[i]!=vp1[i])return false;
        }
        return true;
    }
};
