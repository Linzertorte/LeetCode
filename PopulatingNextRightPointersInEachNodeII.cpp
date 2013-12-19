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
        root->next=NULL;
        TreeLinkNode *p=root;
        TreeLinkNode *head=p;
        while(head){
            p=head;
            head=NULL;
            TreeLinkNode *cur;
            while(p){
                if(p->left){
                    if(!head) head=p->left,cur=head;
                    else cur->next=p->left,cur=cur->next;
                }
                if(p->right){
                    if(!head) head=p->right,cur=head;
                    else cur->next=p->right,cur=cur->next;
                }
                p=p->next;
            }
            
        }
        
        
    }
};
