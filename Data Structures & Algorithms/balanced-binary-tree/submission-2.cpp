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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        bool left_balanced = isBalanced(root->left);
        bool right_balanced = isBalanced(root->right);
        if(left_balanced && right_balanced){
            int left_ht = ht(root->left);
            int right_ht = ht(root->right);
            return abs(left_ht-right_ht)<=1;
        } else {
            return false;
        }
    }

    int ht(TreeNode* root){
        if(!root) return 0;
        int left_ht = ht(root->left);
        int right_ht = ht(root->right);
        return max(left_ht, right_ht)+1;
    }
};
