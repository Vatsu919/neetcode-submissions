struct Trie {
  unordered_map<char, Trie*> mp;
  bool isEnd;
  
};
class PrefixTree {
public:

    Trie* root;
    
    PrefixTree() {
        root = new Trie();
        root->isEnd=false;
    }
    
    void insert(string word) {
        Trie* temp=root;

        for(char c:word) {
            if(temp->mp.find(c)==temp->mp.end()) {
                Trie* nnode = new Trie();
                temp->mp[c]=nnode;
            }
            temp = temp->mp[c];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        Trie* temp=root;
        for(char c:word) {
            if(temp->mp.find(c)==temp->mp.end())return false;
            temp=temp->mp[c];
        }
        return temp->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* temp=root;
        for(char c:prefix) {
            if(temp->mp.find(c)==temp->mp.end())return false;
            temp=temp->mp[c];
        }
        return true;
    }
};
