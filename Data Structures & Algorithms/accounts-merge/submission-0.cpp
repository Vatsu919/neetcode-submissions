class Solution {
public:

    class DSU{
        public:

        vector<int> rank;
        vector<int> parent;

        DSU(int n) {
            rank.resize(n, 1);
            parent.resize(n);

            for(int i=0;i<n;i++) {
                parent[i]=i;
            }
        }

        int find(int x) {
            if(parent[x]!=x) {
                parent[x]=find(parent[x]);
            }
            return parent[x];
        }

        void do_union(int a,int b) {
            int aroot = find(a);
            int broot = find(b);

            if(aroot==broot)return ;

            if(rank[broot]>rank[aroot]) {
                parent[aroot]=broot;
            }
            else if(rank[aroot]>rank[broot]) {
                parent[broot]=aroot;
            }
            else {
                parent[broot]=aroot;
                rank[aroot]++;
            }
        }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> emailToAcc;
        unordered_map<int, vector<string>> tempAns;

        vector<vector<string>> ans;

        DSU dsu(accounts.size());

        for(int i=0;i<accounts.size();i++) {
            for(int j=1;j<accounts[i].size();j++) {
                if(emailToAcc.find(accounts[i][j])!=emailToAcc.end()) {
                    dsu.do_union(emailToAcc[accounts[i][j]], i);
                }
                else {
                    emailToAcc[accounts[i][j]]=i;
                }
            }
        }

        for(auto it:emailToAcc) {
            int rind = dsu.find(it.second);
            tempAns[rind].push_back(it.first);
        }

        for(auto it:tempAns) {
            vector<string> temp;
            sort(it.second.begin(), it.second.end());
            temp.push_back(accounts[it.first][0]);
            for(int i=0;i<it.second.size();i++) {
                temp.push_back(it.second[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};