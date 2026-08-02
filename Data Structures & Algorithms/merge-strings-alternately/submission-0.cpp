class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        string s;
        int i=0,j=0;
        while(i<w1.size() && j<w2.size()) {
            s.push_back(w1[i++]);
            s.push_back(w2[j++]);
        }
        while(i<w1.size())s.push_back(w1[i++]);
        while(j<w2.size())s.push_back(w2[j++]);
        return s;
    }
};