class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(int i=0;i<tokens.size();i++) {
            if(tokens[i]=="*") {
                int s2=st.top();
                st.pop();
                int s1=st.top();
                st.pop();
                st.push(s1*s2);
            }
            else if(tokens[i]=="/") {
                int s2=st.top();
                st.pop();
                int s1=st.top();
                st.pop();
                st.push(s1/s2);
            }
            else if(tokens[i]=="-") {
                int s2=st.top();
                st.pop();
                int s1=st.top();
                st.pop();
                st.push(s1-s2);
            }
            else if(tokens[i]=="+") {
                int s2=st.top();
                st.pop();
                int s1=st.top();
                st.pop();
                st.push(s1+s2);
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
