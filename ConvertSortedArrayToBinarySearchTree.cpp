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
    TreeNode *helper(vector<int> &num,int p,int r){
        if(p>r) return NULL;
        TreeNode *root=(TreeNode *)malloc(sizeof(TreeNode));
        int m=(p+r)/2;
        root->val=num[m];
        root->left=helper(num,p,m-1);
        root->right=helper(num,m+1,r);
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if(!num.size()) return NULL;
        return helper(num,0,num.size()-1);
    }
};
