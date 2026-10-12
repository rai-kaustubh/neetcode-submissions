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
    unordered_map<int, int> indices;
    int pre_idx=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            indices[inorder[i]]=i;
        }

        return helper(preorder, 0, preorder.size()-1);
    }

    TreeNode* helper(vector<int>& preorder, int l ,int r){
        if(l>r) return NULL;

        TreeNode* root = new TreeNode(preorder[pre_idx++]);
        int mid =indices[root->val];
        root->left = helper(preorder, l, mid-1);
        root->right = helper(preorder, mid+1, r);

        return root;
    }
};
/*
preorder = [1,2,3,4], inorder = [2,1,3,4]


*/
