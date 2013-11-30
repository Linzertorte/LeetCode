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
    void append(ListNode *l,ListNode *x){
        ListNode *p=l;
        while(p->next) p=p->next;
        p->next=x;
    }
    int add_sub_lists(ListNode *l1, ListNode *l2){
        if(!l1&&!l2) return 0;
        int carry=add_sub_lists(l1->next,l2->next);
        l1->val+=l2->val+carry;
        if(l1->val>10){
            (l1->val)%=10;
            return 1;
        }
        return 0;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *p1,*p2;
        p1=l1,p2=l2;
        int carry=0;
        int c;
        while(p1&&p2){
            c=p1->val+p2->val+carry;
            p1->val=p2->val=c%10;
            carry=c/10;
            p1=p1->next;
            p2=p2->next;
        }
        if(p1){
            while(p1){
                c=p1->val+carry;
                p1->val=c%10;
                carry=c/10;
                p1=p1->next;
            }
            ListNode* tail=(ListNode *)malloc(sizeof(ListNode));
            tail->val=1,tail->next=NULL;
            if(carry) append(l1,tail);
            return l1;
        }
        if(p2){
            while(p2){
                c=p2->val+carry;
                p2->val=c%10;
                carry=c/10;
                p2=p2->next;
            }
            ListNode* tail=(ListNode *)malloc(sizeof(ListNode));
            tail->val=1,tail->next=NULL;
            if(carry) append(l2,tail);
            return l2;
        }
        ListNode* tail=(ListNode *)malloc(sizeof(ListNode));
        tail->val=1,tail->next=NULL;
        if(carry) append(l2,tail);
        return l2;
    }
};
