/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *p,*q;
        p=q=head;
        while(q){
            while(q && p->val==q->val) q=q->next;
            p->next=q;
            p=q;
            if(q)q=q->next;
        }
        if(p)p->next=NULL;
        return head;
    }
};
