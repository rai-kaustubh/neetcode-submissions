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
    int goodNodes(TreeNode* root) {
        int count =0;
        int _max = root->val;
        dfs(count, _max, root);
        return count;
    }

    void dfs(int &count, int _max, TreeNode* root){
        if(!root) return;
        _max= max(_max, root->val);
        if(_max<=root->val){
            count++;
        }

        dfs(count, _max, root->left);
        dfs(count, _max, root->right);
    }

};
/*
class Solution {
    private static int count ;
    public static void calculateGoodNodes(TreeNode node , int max ){
        if(node == null) {
            return ;
        }
        max = Math.max(max,node.val);
        if(node.val >= max){
            count++;
        }
        calculateGoodNodes(node.left,max);
        calculateGoodNodes(node.right,max);
    }
    public int goodNodes(TreeNode root) {
        
        count = 0;
        if(root == null) return 0;
        
        calculateGoodNodes(root,Integer.MIN_VALUE) ; 
       
        return count;
        
    }
}

*/