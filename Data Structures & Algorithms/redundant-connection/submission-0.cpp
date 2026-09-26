class Solution {
public:
    class DSU{
        public:
        vector<int> parent;
        vector<int> rank;

        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 1);
            for(int i=0;i<n;i++)parent[i]=i;
        }

        int find(int x) {
            if(parent[x]!=x) {
                parent[x]=find(parent[x]);
            }
            return parent[x];
        }

        bool do_union(int a, int b) {
            int aroot = find(a);
            int broot=find(b);
            if(aroot==broot)return false;

            if(rank[aroot]<rank[broot]) {
                parent[aroot]=broot;
                rank[broot]++;
            }
            else {
                parent[broot]=aroot;
                rank[aroot]++;
            }
            return true;
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size()+1);

        for(int i=0;i<edges.size();i++) {
            if(!dsu.do_union(edges[i][0],edges[i][1]))return {edges[i][0], edges[i][1]};
        }
        return {-1,-1};
    }
};
