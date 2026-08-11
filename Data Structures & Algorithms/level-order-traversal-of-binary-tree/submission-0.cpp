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
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        helper(root,  0);
        return res;
    }

    void helper(TreeNode* root, int height){
        if(!root) return;
        if(res.size()<=height){
            res.push_back({});
        }
        res[height].push_back(root->val);
        helper(root->left, height+1);
        helper(root->right, height+1);
    }
};
