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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        while(!q.empty()){
            auto [node, ht] = q.front();
            q.pop();
            if(!node) continue;
            if(ans.size()<ht || ans.size()==0){
                ans.push_back(node->val);
            }

            q.push({node->right, ht+1});
            q.push({node->left, ht+1});
        }

        return ans;
    }
};
/*
 [1,0 - 3,1 - 2,1 - 5,2 - 5,3 ]
    if(ans.size()<ht)
        [1, 3, ]
    else continue;

*/
