class Solution {
public:
    bool fun(unordered_map<char,int> mp1, unordered_map<char,int> mp2) {
        for(auto it:mp2) {
            if(it.second>mp1[it.first]) {
                return false;
            }
        }
        return true;
    }

    bool chec(unordered_map<char, int> mp1, unordered_map<char, int> mp2) {
        for(auto it:mp1) {
            if(it.second>mp2[it.first]) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;

        for(char c:t)mp1[c]++;

        int l=0,r=0;
        string ans;
        int mi=INT_MAX;
        for(r=0;r<s.size();r++) {
            mp2[s[r]]++;
            while(l<r && chec(mp1,mp2)) {
                if(r-l+1<mi) {
                    mi=r-l+1;
                    ans=s.substr(l, r-l+1);
                }
                mp2[s[l]]--;
                l++;
            }
            if(chec(mp1,mp2) && r-l+1<mi) {
                mi=r-l+1;
                ans=s.substr(l, r-l+1);
            }
        }
        return ans;
    }
};
