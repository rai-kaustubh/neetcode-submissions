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
    int kthSmallest(TreeNode* root, int k) {
       vector<int> res;
       inOrder(root, k, res);
       return res[k-1]; 
    }

    void inOrder(TreeNode* root, int k, vector<int> &res){
        if(!root || res.size()>=k) return;
        inOrder(root->left, k, res);
        res.push_back(root->val);
        inOrder(root->right, k, res);
        
    }
};
