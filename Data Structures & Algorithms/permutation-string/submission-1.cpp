class Solution {
public:
    bool fun(vector<int> mp1, vector<int> mp2) {
        for(int i=0;i<mp2.size();i++) {
            if(mp2[i]>mp1[i])return false;
        }
        return true;
    }
    bool perf(vector<int> mp1, vector<int> mp2) {
        for(int i=0;i<mp2.size();i++) {
            if(mp1[i]!=mp2[i])return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> mp1(26,0);
        vector<int> mp2(26,0);

        for(char c:s1)mp1[c-'a']++;


        int l=0,r=0;

        for(r=0;r<s2.size();r++) {
            mp2[s2[r]-'a']++;

            while(l<r && !fun(mp1,mp2)) {
                mp2[s2[l]-'a']--;
                l++;
            }
            if(mp1==mp2)return true;
        }
        return false;
    }
};
