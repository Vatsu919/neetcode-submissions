class Solution {
public:
    string del = "#";
    string encode(vector<string>& strs) {
        string ans;
        for(string s:strs) {
            ans+=to_string(s.size())+del+s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i=0;
        while(i<s.size()) {
            string snu;
            while(i<s.size() && s[i]!='#') {
                snu+=s[i];
                i++;
            }
            i++;
            int num = stoi(snu);
            string temp;
            for(int j=i;j<i+num;j++) {
                temp+=s[j];
            }
            ans.push_back(temp);
            i+=num;
        }
        return ans;
    }
};
