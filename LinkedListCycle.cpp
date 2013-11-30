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
    bool hasCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!head) return false;
        ListNode *p1,*p2;
        p1=head;
        p2=head;
        p2=p2->next;
        if(!p2) return false;
        p2=p2->next;
        while(p1&&p2)
        {
            if(p1==p2) return true;
            p1=p1->next;
            p2=p2->next;
            if(!p2) return false;
            p2=p2->next;
        }
        return false;
    }
};
