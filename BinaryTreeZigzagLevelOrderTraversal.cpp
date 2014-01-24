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
    void zigzag(vector<TreeNode *> level,bool froml,vector<vector<int> > &result){
        if(!level.size()) return;
        vector<int> num;
        if(froml)
            for(int i=0;i<level.size();i++) num.push_back(level[i]->val);
        else for(int i=level.size()-1;i>=0;i--) num.push_back(level[i]->val);
        result.push_back(num);
        vector<TreeNode *> next;
        for(int i=0;i<level.size();i++){
            if(level[i]->left) next.push_back(level[i]->left);
            if(level[i]->right) next.push_back(level[i]->right);
        }
        zigzag(next,1-froml,result);
    }
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if(!root) return result;
        vector<TreeNode *> level;
        level.push_back(root);
        zigzag(level,1,result);
        return result;
    }
};
