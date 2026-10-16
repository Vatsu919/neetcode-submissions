class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> p1(26,0);
        vector<int> p2(26,0);

        for(char c:s1)p1[c-'a']++;

        int i=0,j=0;

        for(j=0;j<s2.size();j++) {
            p2[s2[j]-'a']++;
            while(i<=j && p2[s2[j]-'a']>p1[s2[j]-'a']) {
                p2[s2[i]-'a']--;
                i++;
            }
            for(int k=0;k<26;k++) {
                if(p1[k]!=p2[k])break;
                if(k==25)return true;
            }
        }
        return false;
    }
};
