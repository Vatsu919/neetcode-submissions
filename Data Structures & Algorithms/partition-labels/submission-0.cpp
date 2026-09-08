class Solution {
public:
    vector<int> partitionLabels(string s) {
        int far=0;
        int ans=0;

        vector<int> mp(26,-1);
        for(int i=0;i<s.size();i++) {
            mp[s[i]-'a']=i;
        }

        int i=0;
        vector<int> sol;
        while(i<s.size()) {
            far=max(far,mp[s[i]-'a']);
            ans++;
            if(i>=far){
                sol.push_back(ans);
                ans=0;
            }
            i++;

        }
        return sol;
    }
};
