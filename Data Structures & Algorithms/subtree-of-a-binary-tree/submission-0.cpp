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

class Solution {
public:
    bool ans=false;
    bool isSameTree(TreeNode* p, TreeNode* q){
        if(!p && !q)return true;
        if(p && !q)return false;
        if(!p && q)return false;
        if(p->val!=q->val)return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right, q->right);
    }
    void trav(TreeNode* root, TreeNode* sub) {
        if(!root)return ;
        trav(root->left, sub);
        if(isSameTree(root, sub)) {
            ans=true;
        }
        trav(root->right, sub);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        ans=false;
        trav(root, subRoot);
        return ans;
    }
};
