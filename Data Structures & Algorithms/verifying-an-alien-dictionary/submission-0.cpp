class Solution {
public:
    unordered_map<char,int> mp;
    bool isValid(string a, string b) {
        int i=0;
        while(i<a.size() && i<b.size() && a[i]==b[i])i++;

        if(i>=a.size())return true;
        else if(i>=b.size())return false;
        return mp[a[i]]<mp[b[i]];
    }
    bool isAlienSorted(vector<string>& words, string order) {
        

        for(int i=0;i<order.size();i++) {
            mp[order[i]]=i;
        }

        for(int i=1;i<words.size();i++) {
            if(!isValid(words[i-1],words[i]))return false;
        }
        return true;
    }
};