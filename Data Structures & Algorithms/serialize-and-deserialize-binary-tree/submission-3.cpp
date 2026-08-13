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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res="";
        preorder(root, res);
        // cout<<res<<endl;
        return res;
    }

    void preorder(TreeNode* root, string &res){
        if(!root){
            res+="N,";
            return;
        } 

        res+=to_string(root->val)+',';
        preorder(root->left, res);
        preorder(root->right, res);
        return;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> preorder;
        int i=0;
        while(i<data.length()){
            int j=i+1;
            while(j<data.length() && data[j]!=','){
                j++;
            }

            if(data[i]!='N'){
                preorder.push_back(stoi(data.substr(i, j-i)));
            } else{
                preorder.push_back(INT_MIN);
            }
            i=j+1;
        }

        // for(auto x: preorder){
        //     cout<<x<<" ";
        // }
        i=0;
        return dfs(i, preorder);
        // return NULL;
    }

    TreeNode* dfs(int &i, vector<int>& preorder){
        if(preorder[i]==INT_MIN){
            // i++;
            return NULL;
        }

        TreeNode* root= new TreeNode(preorder[i]);
        i++;
        root->left = dfs(i, preorder);
        i++;
        root->right = dfs(i, preorder);

        return root;
    }
};
