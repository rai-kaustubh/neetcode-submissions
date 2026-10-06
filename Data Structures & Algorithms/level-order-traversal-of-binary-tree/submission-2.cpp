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
    vector<vector<int>> levelOrder(TreeNode* root) {
        int h = ht(root);
        vector<vector<int>> ans(h);

        queue<pair<TreeNode*, int>> q;
        q.push({root,0});

        while(!q.empty()){
            auto [node, height] = q.front();
            q.pop();
            if(!node) continue;
            
            ans[height].push_back(node->val);

            q.push({node->left, height+1});
            q.push({node->right, height+1});
        }

        return ans;
    }

    int ht(TreeNode* root){
        if(!root) return 0;

        auto left_ht = ht(root->left);
        auto right_ht = ht(root->right);
        return max(left_ht, right_ht)+1;
    }
};
/*
q<TreeNode*, int (ht)>
[(2,1), (3,1), (4,2), (5,2), (6,2), (7,2)]

*/
