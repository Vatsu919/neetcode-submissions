/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    void fun(TreeNode* root, string &s) {
        if(!root) {
            s+="N,";
            return ;
        }
        s+=to_string(root->val)+",";
        fun(root->left,s);
        fun(root->right,s);
    }
    string serialize(TreeNode* root) {
        string ans;
        fun(root,ans);
        return ans;
    }

    TreeNode* sol(vector<string> &vp, int &ind) {
        if(ind>=vp.size())return NULL;
        if(vp[ind]=="N") {
            ind++;
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(vp[ind]));
        ind++;
        TreeNode* left = sol(vp, ind);
        TreeNode* right = sol(vp, ind);
        root->left=left;
        root->right=right;
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        data.pop_back();
        stringstream ss(data);
        vector<string> vp;
        string word;
        while (getline(ss, word, ',')) {
            vp.push_back(word);
        }
        int ind=0;
        return sol(vp, ind);
    }
};
