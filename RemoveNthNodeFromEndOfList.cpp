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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *p0,*p1,*pn;
        p0=p1=pn=head;
        while(--n) pn=pn->next;
        while(pn->next){
            pn=pn->next;
            p0=p1;
            p1=p1->next;
        }
        if(p0==p1) return head->next;
        p0->next=p1->next;
        return head;
        
    }
};
