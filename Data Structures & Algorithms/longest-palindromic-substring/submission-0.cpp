class Solution {
public:
    string longestPalindrome(string s) {
        string ans;

        for(int i=0;i<s.size();i++) {
            int j=i, k=i;
            while(j>=0 && k<s.size() && s[j]==s[k]) {
                j--;
                k++;
            }
            j++;
            k--;
            if(k-j+1>ans.size()) {
                ans=s.substr(j,k-j+1);
            }

            if(i!=s.size()-1) {
                j=i,k=i+1;
                while(j>=0 && k<s.size() && s[j]==s[k]) {
                    j--;
                    k++;
                }
                j++;
                k--;
                if(k-j+1>ans.size()) {
                    ans=s.substr(j,k-j+1);
                }
            }
        }
        return ans;
    }
};
