class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;

        while(i<j) {
            if(!(s[i]>='A' && s[i]<='Z') && !(s[i]>='a' && s[i]<='z') && !(s[i]>='0' && s[i]<='9')) {
                i++;
                continue;
            }
            if(!(s[j]>='A' && s[j]<='Z') && !(s[j]>='a' && s[j]<='z') && !(s[j]>='0' && s[j]<='9')) {
                j--;
                continue;
            }
            char c1=tolower(s[i]);
            char c2=tolower(s[j]);
            if(c1!=c2)return false;
            i++;
            j--;
        }
        return true;
    }
};
