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
    TreeNode* fun(vector<int> &pre, vector<int> &ino, int i,int j, int ind) {
        if(i>j)return NULL;
        if(i==j) {
            return new TreeNode(ino[i]);
        }
        int val = pre[ind];
        int rind;
        for(int k=i;k<=j;k++) {
            if(ino[k]==val) {
                rind=k;
                break;
            }
        }
        TreeNode* left = fun(pre,ino,i,rind-1,ind+1);
        TreeNode* right = fun(pre,ino,rind+1,j,ind + 1 + (rind - i));
        TreeNode* node = new TreeNode(val);
        node->left=left;
        node->right=right;
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return fun(preorder,inorder,0,preorder.size()-1,0);
    }
};
