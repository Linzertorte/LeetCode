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
    //swap first two nodes, return head
    ListNode *swap_two(ListNode *p){
        if(!p || !p->next) return p;
        ListNode *q=p->next;
        p->next=q->next;
        q->next=p;
        
        return q;
    }
    ListNode *swapPairs(ListNode *head) {
        head=swap_two(head);
        ListNode *p=head;
        ListNode *q;
        while(p && p->next){
            q=p->next;
            p=swap_two(p->next->next);
            q->next=p;
        }
        return head;
    }
};
