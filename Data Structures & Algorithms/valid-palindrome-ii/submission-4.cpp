class Solution {
public:
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1;
        while(i<j) {
            if(s[i]==s[j]) {
                i++;
                j--;
            }
            else return isP(i+1,j,s) || isP(i,j-1,s);
        }
        return true;
    }

    bool isP(int l, int r, string s) {
        while(l<r) {
            if(s[l]!=s[r])return false;
            l++;
            r--;
        }
        return true;
    }
};