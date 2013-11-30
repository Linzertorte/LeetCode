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
    void dfs(TreeNode *root, vector<int>& path, int accu, int sum, vector<vector<int> > &result){
        path.push_back(root->val);
        if(!root->left && !root->right) {
            if(accu+root->val==sum) result.push_back(path);
            path.pop_back();
            return;
        }
        
        if(root->left)dfs(root->left,path,accu+root->val,sum,result);
        
        if(root->right)dfs(root->right,path,accu+root->val,sum,result);
        path.pop_back();
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > result;
        vector<int> path;
        if(!root) return result;
        dfs(root,path,0,sum,result);
        return result;
    }
};
