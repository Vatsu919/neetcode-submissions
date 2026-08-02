#include<bits/stdc++.h>
class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for(string x:strs) {
            encoded+=to_string(x.size()) + "#" + x;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int i=0;
        while(i<s.size()) {
            string temp;
            string num;
            while(i<s.size() && s[i]!='#') {
                num.push_back(s[i]);
                i++;
            }
            // cout<<num<<endl;
            int n=stoi(num);
            i++;
            for(int j=0;j<n;j++) {
                temp.push_back(s[i+j]);
            }
            i+=n;
            ans.push_back(temp);
        }
        return ans;
    }
};
