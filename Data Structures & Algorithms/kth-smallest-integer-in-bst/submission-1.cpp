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
    vector<int> ans;
    int kthSmallest(TreeNode* root, int k) {
        ans.clear();
        inOrder(root, k);
        return ans.back();
    }

    void inOrder(TreeNode* root, int k){
        if(!root) return;
        if(ans.size()==k) return;

        inOrder(root->left, k);
        if(ans.size()==k) return;
        ans.push_back(root->val);
        inOrder(root->right,k);
    }
};
