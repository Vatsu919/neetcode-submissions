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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};

        queue<TreeNode*> q;
        vector<int> ans;
        q.push(root);

        while(!q.empty()) {
            int s=q.size();
            int fs=q.size();
            while(s--) {
                TreeNode* u=q.front();
                q.pop();
                if(s==0) {
                    ans.push_back(u->val);
                }
                if(u->left) q.push(u->left);
                if(u->right) q.push(u->right);
            }
        }
        return ans;
    }
};
