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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return helper(root->left, root->val, INT_MIN) &&
                helper(root->right, INT_MAX, root->val); 
    }

    bool helper(TreeNode* root, int _max, int _min){
        if(!root) return true;

        if(root->val >= _max || root->val <= _min){
            return false;
        }

        return helper(root->left, root->val, _min) &&
                helper(root->right, _max, root->val);
    }
};
