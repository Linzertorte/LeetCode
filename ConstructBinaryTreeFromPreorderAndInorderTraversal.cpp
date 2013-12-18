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

    TreeNode *build(vector<int> &preorder,int p1,int q1,vector<int> &inorder,int p2,int q2){
        if(p1>q1) return NULL;
        TreeNode *t=new TreeNode(preorder[p1]);
        int x=t->val;
        int i;
        for(i=p2;i<=q2;i++)
            if(inorder[i]==x) break;
        int left=i-p2;
        t->left=build(preorder,p1+1,p1+left,inorder,p2,p2+left-1);
        t->right=build(preorder,p1+left+1,q1,inorder,p2+left+1,q2);
        return t;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};
