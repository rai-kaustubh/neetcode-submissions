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
    unordered_map<int, int> _map;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size()==0 || preorder.size()==0) return NULL;
        for(int i=0;i<inorder.size();i++){
            _map[inorder[i]]=i;
        }

        return dfs(preorder, 0, inorder.size()-1);
    }

    TreeNode* dfs(vector<int> &preorder, int l, int r){
        if(l>r) return NULL;
        int val= preorder[pre_idx++];
        int mid = _map[val];
        TreeNode* node = new TreeNode(val);

        node->left = dfs(preorder, l, mid-1);
        node->right = dfs(preorder, mid+1, r);
        return node;
    }
};
