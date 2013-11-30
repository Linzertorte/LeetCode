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
    bool expanded;
    Node(TreeNode *_t,bool b){
        t=_t;
        expanded=b;
    }
};
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> ans;
        stack<Node> st;
        st.push(Node(root,false));
        Node node(root,false);
        if (!root) return ans;
        while(!st.empty()){
            node = st.top();
            if(node.expanded) ans.push_back(node.t->val),st.pop();
            else {
                 st.top().expanded=true;
                 if(node.t->right) st.push(Node(node.t->right,false));
                 if(node.t->left) st.push(Node(node.t->left,false));
            }
            
        }
        return ans;
    }
};
