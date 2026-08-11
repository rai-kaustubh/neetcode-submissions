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
    int res;
    int diameterOfBinaryTree(TreeNode* root) {
        res=0;
        logic(root);
        return res;
    }

    int logic(TreeNode* root){
        if(!root) return 0;

        int l=logic(root->left);
        int r=logic(root->right);
        res = max(l+r, res);

        return 1+ max(l,r);

    }
};
