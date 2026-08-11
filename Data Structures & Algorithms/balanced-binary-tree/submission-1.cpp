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
    bool res;
    bool isBalanced(TreeNode* root) {
        res=true;
        isBalancedLogic(root);
        return res;
    }

    int isBalancedLogic(TreeNode* root){
        if(!root) return 0;
        int lh = isBalancedLogic(root->left);
        int rh = isBalancedLogic(root->right);

        res = res && (abs(lh-rh)<=1);
        return max(lh, rh)+1;
    }
};
