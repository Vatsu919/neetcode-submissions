class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> vp1(128,0);
        vector<int> vp2(128,0);
        int need = 0;
        for(int i=0;i<t.size();i++) {
            if(vp2[t[i]]==0){
                need++;
            }
            vp2[t[i]]++;
        }
       
        int have=0;

        int j=0,i=0;
        int ai=-1, aj=-1;

        for(j=0;j<s.size();j++) {
            vp1[s[j]]++;
            if(vp1[s[j]]==vp2[s[j]]) {
                have++;
            }

            while(i<=j && have==need) {
                if(ai==-1) {
                    ai=i,aj=j;
                }
                else if(j-i+1<aj-ai+1) {
                    ai=i,aj=j;
                }
                if(vp1[s[i]]==vp2[s[i]]) {
                    have--;
                }
                vp1[s[i]]--;
                i++;
            }
        }
        if(ai==-1)return "";
        return s.substr(ai,aj-ai+1);
    }
};
