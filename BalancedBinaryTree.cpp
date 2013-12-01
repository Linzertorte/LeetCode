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
    bool Balanced(TreeNode* root,int &c) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!root){
            c=0;
            return true;
        }
        int a,b;
        if(!Balanced(root->left,a)) return false;
        if(!Balanced(root->right,b)) return false;
        c=max(a,b)+1;
        return abs(a-b)<=1;
    }
    bool isBalanced(TreeNode* root){
        int a;
        return Balanced(root,a);
    }
};
