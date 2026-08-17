class Solution {
public:
    int countSubstrings(string s) {
        int ans=0;

        for(int i=0;i<s.size();i++) {
            int j=i,k=i;

            while(j>=0 && k<s.size() && s[j]==s[k]) {
                ans++;
                j--;
                k++;
            }

            j=i,k=i+1;

            while(j>=0 && k<s.size() && s[j]==s[k]) {
                ans++;
                j--;
                k++;
            }
        }

        return ans;
    }
};
