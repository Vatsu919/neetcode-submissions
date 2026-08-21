class Solution {
public:
    bool isConn(string w1, string w2) {
        int ct=0;
        for(int i=0;i<w1.size();i++) {
            if(w1[i]!=w2[i])ct++;
            if(ct>1)return false;
        }
        return ct==1;
    }

    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord==endWord)return 1;
        unordered_map<string, vector<string>> g;
        for(int i=0;i<wordList.size()-1;i++) {
            if(isConn(wordList[i], beginWord)) {
                g[beginWord].push_back(wordList[i]);
                g[wordList[i]].push_back(beginWord);
            }
            for(int j=i+1;j<wordList.size();j++) {
                if(isConn(wordList[i], wordList[j])) {
                    g[wordList[i]].push_back(wordList[j]);
                    g[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        queue<string> q;
        q.push(beginWord);

        unordered_map<string, bool> visited;
        visited[beginWord]=true;
        int l=0;
        bool found=false;
        while(!q.empty()) {
            int s=q.size();
            while(s--) {
                string u=q.front();

                q.pop();
                if(u==endWord) {
                    found=true;
                    return l+1;
                }

                for(string v:g[u]) {
                    if(visited.find(v)==visited.end()) {
                        visited[v]=true;
                        q.push(v);
                    }
                }
            }
            l++;
        }
        return found?l:0;
    }
};
