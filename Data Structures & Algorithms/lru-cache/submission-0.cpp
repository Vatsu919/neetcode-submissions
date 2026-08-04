class LNode {
public:
    int key;
    int val;
    LNode* next;
    LNode* prev;

    LNode(int key,int val) {
        this->key=key;
        this->val=val;
    }
};

class LList{
public:
LNode* first;
LNode* last;

 LList() {
    first = new LNode(-1,-1);
    last = new LNode(-1,-1);
    first->next=last;
    last->prev=first;
 }

 LNode* addFirst(int key, int val) {
    LNode* nnode = new LNode(key,val);

    LNode* next=first->next;
    first->next=nnode;
    nnode->next=next;
    next->prev=nnode;
    nnode->prev=first;
    return nnode;
 }

 void rm(LNode* node) {
    LNode* prev = node->prev;
    LNode* next = node->next;

    prev->next=next;
    next->prev=prev;
    delete(node);
 }

 int delLast() {
    LNode* node = last->prev;
    int key=node->key;
    rm(node);
    return key;
 }
};
class LRUCache {
public:
    int cap;
    unordered_map<int, LNode*> mp;
    LList* nlist;
    LRUCache(int capacity) {
        nlist=new LList();
        cap=capacity;
    }
    
    int get(int key) {
      
        if(mp.find(key)==mp.end())return -1;
        LNode* vnode = mp[key];
        int val = vnode->val;
        nlist->rm(vnode);
        mp[key] = nlist->addFirst(key, val);
        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()) {
            LNode* vnode = mp[key];
            nlist->rm(vnode);
            mp[key] = nlist->addFirst(key,value);
            return ;
        }
        if(mp.size()==cap) {
            int dkey = nlist->delLast();
            mp.erase(dkey);
        }
        mp[key] = nlist->addFirst(key,value);
    }
};
