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
    int ans=0;
    int maxi = INT_MIN;
    int goodNodes(TreeNode* root) {
        countGoodNodes(root, maxi);
        return ans;
    }

    void countGoodNodes(TreeNode* root,int maxi ){
        if(!root) return ;
        if(root->val>=maxi){
            ans++;
        }

        maxi = max(maxi, root->val);
        countGoodNodes(root->left, maxi);
        countGoodNodes(root->right, maxi);
    }
};
/*
root=[1,2,-1,3,4]

*/
