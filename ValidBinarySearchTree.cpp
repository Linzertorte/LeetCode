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
    void inOrderTraverse(TreeNode *root, vector<int> &keys){
        if(root->left)inOrderTraverse(root->left,keys);
        keys.push_back(root->val);
        if(root->right) inOrderTraverse(root->right,keys);
    }
    bool isValidBST(TreeNode *root) {
        vector<int> keys;
        if(!root) return true;
        inOrderTraverse(root,keys);
        for(int i=0;i<keys.size()-1;i++)
        if(keys[i]>=keys[i+1]) return false;
        return true;
        
    }
};
