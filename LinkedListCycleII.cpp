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
    ListNode *detectCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *turtle=head;
        ListNode *rabbit=head;
        while(turtle){
            turtle=turtle->next;
            if(rabbit) rabbit=rabbit->next;
            else break;
            if(rabbit) rabbit=rabbit->next;
            else break;
            if(rabbit==turtle) break;
        }
        if(!rabbit) return NULL;
        ListNode *p=head;
        while(p!=turtle) turtle=turtle->next,p=p->next;
        return turtle;
        
    }
};
