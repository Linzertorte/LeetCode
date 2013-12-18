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

    TreeNode *build(vector<int> &inorder,int p1,int q1,vector<int> &postorder,int p2,int q2){
        if(p1>q1) return NULL;
        TreeNode *t=new TreeNode(postorder[q2]);
        int x=t->val;
        int i;
        for(i=p1;i<=q1;i++)
            if(inorder[i]==x) break;
        int left=i-p1;
        t->left=build(inorder,p1,p1+left-1,postorder,p2,p2+left-1);
        t->right=build(inorder,p1+left+1,q1,postorder,p2+left,q2-1);
        return t;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
};
