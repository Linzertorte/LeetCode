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
    void tail(vector<TreeNode *> &level, vector<vector<int> >&result){
        if(!level.size()) return;
        vector<TreeNode *> next;
        
        for(int i=0;i<level.size();i++){
            if(level[i]->left) next.push_back(level[i]->left);
            if(level[i]->right) next.push_back(level[i]->right);
        }
        tail(next,result);
        vector<int> levelval;
        for(int i=0;i<level.size();i++)
            levelval.push_back(level[i]->val);
        result.push_back(levelval);
        
    }
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;
        if(!root) return result;
        vector<TreeNode *> level;
        level.push_back(root);
        tail(level,result);
    }
};
