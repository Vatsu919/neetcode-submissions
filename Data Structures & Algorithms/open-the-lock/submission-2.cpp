class Solution {
public:
    pair<char,char> getNext(char c) {
        int n = c - '0';
        if(n==0) {
            return {'9', '1'};
        }
        return {(n-1)+'0', (n+1)%10 + '0'};
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string,bool> visited;
        visited["0000"]=true;
        set<string> st;
        for(string s:deadends)st.insert(s);
        if(st.find("0000")!=st.end())return -1;

        int l=0;

        queue<string> q;
        q.push("0000");

        while(!q.empty()) {
            int s=q.size();

            while(s--) {
                string u=q.front();
                q.pop();
                if(u==target)return l;

                for(int i=0;i<4;i++) {
                    pair<char,char> nc = getNext(u[i]);
                    string v1=u;
                    v1[i]=nc.first;
                    string v2=u;
                    v2[i]=nc.second;
                    if(visited.find(v1)==visited.end() && st.find(v1)==st.end()) {
                        q.push(v1);
                        visited[v1]=true;
                    }
                    if(visited.find(v2)==visited.end() && st.find(v2)==st.end()) {
                        q.push(v2);
                        visited[v2]=true;
                    }
                }
            }
            l++;
        }
        return -1;
    }
};