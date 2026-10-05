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

        int left_ht = ht(root->left);
        int right_ht = ht(root->right);
        return max(left_ht+right_ht, max_dia);
        
    }

    int ht(TreeNode* root){
        if(!root) return 0;

        int left_ht = ht(root->left);
        int right_ht = ht(root->right); 
        max_dia = max(left_ht + right_ht, max_dia);
        return max(left_ht, right_ht)+1;
    }
};


