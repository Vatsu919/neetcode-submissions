/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return head;
        unordered_map<Node*, Node*> mp;
        mp[head] = new Node(head->val);

        Node* temp=head;

        while(temp) {
            if(temp->random && mp.find(temp->random)==mp.end()) {
                mp[temp->random] = new Node(temp->random->val);
            }
            mp[temp]->random = mp[temp->random];
            if(temp->next && mp.find(temp->next)==mp.end()) {
                mp[temp->next] = new Node(temp->next->val);
            }
            mp[temp]->next=mp[temp->next];
            temp=temp->next;
        }
        return mp[head];
    }
};
