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
    int ans =INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }

    int dfs(TreeNode* root){
        if(!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);

        ans = max(ans, max(left+root->val+right, max(left+root->val, max(right+root->val, root->val))));
        return max(left+root->val, max(right+root->val, root->val));
    }
};
