/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)return NULL;
        unordered_map<Node*, Node*> mp;

        Node* snode = new Node(node->val);
        mp[node]=snode;

        queue<Node*> q;
        q.push(node);

        while(!q.empty()) {
            Node* unode = q.front();
            q.pop();

            for(Node* vnode:unode->neighbors) {
                if(mp.find(vnode)==mp.end()) {
                    Node* nnode = new Node(vnode->val);
                    mp[vnode]=nnode;
                    q.push(vnode);
                }
                mp[unode]->neighbors.push_back(mp[vnode]);
            }
        }
        return mp[node];
    }
};
