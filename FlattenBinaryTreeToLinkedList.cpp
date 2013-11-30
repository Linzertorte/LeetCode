/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //give the root
    //return the last node's TreeNode
    TreeNode **flatten_sub(TreeNode *root){
        if(!root->left && !root->right) return &(root->right);
        if(!root->left) return flatten_sub(root->right);
        if(!root->right) {
            root->right=root->left;
            root->left=NULL;
            return flatten_sub(root->right);
        }
        TreeNode *right=root->right;
        
        TreeNode ** ret=flatten_sub(root->right);
        TreeNode ** last=flatten_sub(root->left);
        *last=right;
        root->right=root->left;
        root->left=NULL;
        return ret;
    }
    void flatten(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!root) return;
        flatten_sub(root);
    }
};
