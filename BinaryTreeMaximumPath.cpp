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
    
    int dfs(TreeNode *t,int &lmax,int &rmax){
        if(!t){
            lmax=rmax=INT_MIN/2;
            return INT_MIN/2;
        }
        int l,r,m1,m2;
        
        m1=dfs(t->left,l,r);
        lmax=max(max(l,r)+t->val,t->val);
        
        m2=dfs(t->right,l,r);
        rmax=max(max(l,r)+t->val,t->val);
      
        
        return max(lmax+rmax-t->val,max(m1,m2));
        
    }
    
    int maxPathSum(TreeNode *root) {
        int l,r;
        return dfs(root,l,r);
    }
};
