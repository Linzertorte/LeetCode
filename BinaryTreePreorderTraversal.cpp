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
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);
        if (!root) return ans;
        while(!st.empty()){
            TreeNode* t = st.top();
            ans.push_back(t->val),st.pop();
     
                 if(t->right) st.push(t->right);
                 if(t->left) st.push(t->left);
            
            
        }
        return ans;
    }
};

