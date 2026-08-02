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
        int left=fun(root->left);
        int right=fun(root->right);

        ans = max(ans, left+root->val+right);
        return max(0, max(root->val+left, root->val+right));
    }
    int maxPathSum(TreeNode* root) {
        ans=INT_MIN;
        fun(root);
        return ans;
    }
};
