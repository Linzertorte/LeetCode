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
    void dfs(TreeNode *root,int &path,int &sum){
        path=path*10+root->val;
        if(!root->left && !root->right){
            sum+=path;
            path/=10;
            return ;
        }
        if(root->left) {
            dfs(root->left,path,sum);
          
        }
        if(root->right){
            dfs(root->right,path,sum);
            
        }
        path/=10;
    }
    int sumNumbers(TreeNode *root) {
        int path=0;
        int sum=0;
        if(!root) return sum;
        dfs(root,path,sum);
        return sum;
    }
};
