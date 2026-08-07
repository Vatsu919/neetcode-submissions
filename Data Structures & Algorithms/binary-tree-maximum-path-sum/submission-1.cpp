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
    int ans=INT_MIN;
    int fun(TreeNode* root) {
        if(!root)return 0;
        int left = fun(root->left);
        int right = fun(root->right);
        left=max(left,0);
        right=max(right,0);
        ans=max(ans,left+root->val);
        ans=max(ans,right+root->val);
        ans=max(ans,left+root->val+right);
        return max(left, right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        fun(root);
        return ans;
    }
};
