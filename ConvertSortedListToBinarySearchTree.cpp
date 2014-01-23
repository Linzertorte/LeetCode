/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    int getLength(ListNode *head){
        int cnt=0;
        while(head) cnt++,head=head->next;
        return cnt;
    }
    TreeNode *build(int l,int r,ListNode *&p){
        if(l>r){

            return NULL;
        }
        int mid=(l+r)>>1;
        TreeNode *t=new TreeNode(0);
        t->left=build(l,mid-1,p);
        t->val=p->val;
        p=p->next;
        t->right=build(mid+1,r,p);
        return t;
        
    }
    TreeNode *sortedListToBST(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len=getLength(head);
        if(!len) return NULL;
        ListNode *p=head;
        return build(0,len-1,p);
    }
};
