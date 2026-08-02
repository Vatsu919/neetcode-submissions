class ListNode {
    public:
        int key;
        int val;
        ListNode* next;
        ListNode(int key, int val) {
            this->key = key;
            this->val = val;
            this->next=NULL;
        }
};

class Llist{
    public:
        ListNode* root;

        Llist() {
            root = new ListNode(-1,-1);
        }

        int findValue(int key) {
            ListNode* temp=root;
            while(temp) {
                if(temp->key==key)return temp->val;
                temp=temp->next;
            }
            return -1;
        }

        void insert(int key, int val) {
            ListNode* temp = root;
            while(temp) {
                if(temp->key==key) {
                    temp->val=val;
                    return ;
                }
                temp=temp->next;
            }
            ListNode* nnode = new ListNode(key,val);
            nnode->next=root->next;
            root->next=nnode;
        }


        void remove(int key) {
            ListNode* prev = root;
            ListNode* temp = root;

            while(temp) {
                if ((temp)->key == key) {
                    (prev)->next = (temp)->next;
                    delete temp; 
                    // print();
                    return ;             
                }
                prev = temp;
                temp = (temp)->next;
            }
        }
};

class MyHashMap {
public:
    vector<Llist> vp;
    int k;
    MyHashMap() {
        vp.resize(10000);
        k=10000;
    }
    
    void put(int key, int value) {
        int hash = key%k;
        vp[hash].insert(key,value);
    }
    
    int get(int key) {
        int hash=key%k;
        return vp[hash].findValue(key);
    }
    
    void remove(int key) {
        int hash=key%k;
        vp[hash].remove(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */