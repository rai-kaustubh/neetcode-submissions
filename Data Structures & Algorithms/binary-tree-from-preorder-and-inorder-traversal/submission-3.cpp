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
    int pre_idx=0;
    unordered_map<int, int> indices;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            indices[inorder[i]]=i;
        }   

        return helper(preorder, 0, inorder.size()-1); 
    }

    TreeNode* helper(vector<int>& preorder, int l, int r){
        if(l>r) return NULL;
        TreeNode* root = new TreeNode(preorder[pre_idx++]);
        int mid = indices[root->val];

        root->left = helper(preorder, l, mid-1);
        root->right = helper(preorder, mid+1, r);

        return root;
    }
};
