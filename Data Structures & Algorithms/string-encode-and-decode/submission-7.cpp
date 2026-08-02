class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;

        for(int i=0;i<strs.size();i++) {
            ans+=to_string(strs[i].size())+"#"+strs[i];
        }
        return ans;
    }

   vector<string> decode(string s) {
    vector<string> ans;
    int i = 0;

    while (i < s.size()) {
        string sz;

        while (i < s.size() && s[i] != '#') {
            sz += s[i];
            i++;
        }

        int nsz = stoi(sz);
        i++;

        string sk;
        for (int j = i; j < i + nsz; j++) {
            sk.push_back(s[j]);
        }

        ans.push_back(sk);
        i += nsz;
    }

    return ans;
}
};