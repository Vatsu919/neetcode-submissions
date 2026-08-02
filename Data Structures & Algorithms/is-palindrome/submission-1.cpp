class Solution {
public:
    bool cmp(char a, char b) {
        if(a>='A' && a<='Z')a=tolower(a);
        if(b>='A' && b<='Z')b=tolower(b);
        return a==b;
    }
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

            if(!cmp(s[i], s[j]))return false;
            else {
                i++;
                j--;
            }

        }
        return true;
    }
};
