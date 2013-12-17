/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Node{
    TreeNode *t;
    int leftPrinted;
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> result;
        if(!root) return result;
        stack<Node> st;
        st.push(Node{root,0});
        while(!st.empty()){
            Node n=st.top();
            st.pop();
            TreeNode *t=n.t;
            if(n.leftPrinted) {
                result.push_back(t->val);
                if(t->right)st.push(Node{t->right,0});
            }
            else{
                //add left add itself
                st.push(Node{t,1});
                if(t->left)st.push(Node{t->left,0});
                
            }
            
        }
        
    }
};
