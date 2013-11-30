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

    vector<int> get_level(vector<TreeNode *> &cur){
        vector<int> res;
        for(int i=0;i<cur.size();i++)
            res.push_back(cur[i]->val);
        vector<TreeNode *> next;
        for(int i=0;i<cur.size();i++)
            {
                if(cur[i]->left) next.push_back(cur[i]->left);
                if(cur[i]->right) next.push_back(cur[i]->right);
            }
        cur=next;
        return res;
    }
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if(!root) return result;
        vector<int> level;
        vector<TreeNode *> tree_level;
        tree_level.push_back(root);
        
        while(level=get_level(tree_level),level.size())
            result.push_back(level);
          
          return result;
        
    }
};
