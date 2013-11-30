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
    int minDepth(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int res=INT_MAX;
        if(root->left) res=min(res,1+minDepth(root->left));
        if(root->right) res=min(res,1+minDepth(root->right));
        return res;
    }
};
