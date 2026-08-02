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
    bool ans = true;
    pair<int,int> fun(TreeNode* root) {
        if(!root)return {INT_MAX, INT_MIN};
        pair<int,int> left=fun(root->left);
        pair<int,int> right = fun(root->right);

        if(left.second>=root->val || right.first<=root->val)ans=false;

        return {min(root->val, left.first), max(root->val, right.second)};
    }
    bool isValidBST(TreeNode* root) {
        ans=true;
        fun(root);
        return ans;
    }
};
