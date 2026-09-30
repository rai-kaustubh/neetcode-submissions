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
int max_dia = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int left_dia = diameterOfBinaryTree(root->left);
        int right_dia = diameterOfBinaryTree(root->right);
        int left_ht = ht(root->left);
        int right_ht = ht(root->right);
        return max(left_ht+right_ht, max(left_dia, right_dia));
    }

    int ht(TreeNode* root){
        if(!root) return 0;

        int left_ht = ht(root->left);
        int right_ht = ht(root->right); 

        return max(left_ht, right_ht)+1;
    }
};


