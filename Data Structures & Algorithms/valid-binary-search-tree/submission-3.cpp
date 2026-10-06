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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        ans.clear();
        // cout<<ans.size();
        inOrder(root);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
            if(i!=ans.size()-1 && ans[i]>=ans[i+1]){
                return false;
            }
        }

        return true;
    }

    void inOrder(TreeNode* root){
        if(!root) return;
        // if(root->

        inOrder(root->left);
        ans.push_back(root->val);
        inOrder(root->right);

        return;
    }
};
/*

*/

