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
    int idx=0;
    unordered_map<int, int> _map;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            _map[inorder[i]]=i;
        }

        return dfs(preorder, 0, inorder.size()-1);
    }

    TreeNode* dfs(vector<int>& inorder, int l, int r){
        if(l>r) return NULL;
        int val = inorder[idx++];
        TreeNode* root = new TreeNode(val);
        int mid = _map[val];

        root->left = dfs(inorder, l, mid-1);
        root->right = dfs(inorder, mid+1, r);

        return root;
    }
};
