/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        connect(root->left);
        connect(root->right);
        TreeLinkNode *p,*q;
        p=root->left;
        q=root->right;
        while(p){
            p->next=q;
            p=p->right;
            q=q->left;
        }
    }
};
