class Solution {
public:
    bool isValid(char c) {
        return (c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9');
    }
    char getVal(char c) {
        if(c>='0' && c<='9')return c;
        return tolower(c);
    }
    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;

        while(i<j) {
            if(!isValid(s[i])) {
                i++;
            }
            else if(!isValid(s[j])) {
                j--;
            }
            else {
                char c1=getVal(s[i]);
                char c2=getVal(s[j]);
                if(c1==c2) {
                    i++;
                    j--;
                }
                else return false;
            }
        }
        return true;
    }
};
