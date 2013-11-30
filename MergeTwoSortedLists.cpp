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
    ListNode *nextNode(ListNode **l1,ListNode **l2){
        ListNode *ret;
        if(!(*l1)){
            ret=*l2;
            *l2=(*l2)->next;
            return ret;
        }
        if(!(*l2)){
            ret=*l1;
            *l1=(*l1)->next;
            return ret;
        }
        
        if((*l1)->val<(*l2)->val){
            ret=*l1;
            *l1=(*l1)->next;
            return ret;
        }
        ret=*l2;
        *l2=(*l2)->next;
        return ret;
        
    }
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(!l1 && !l2) return l1;
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode *l=nextNode(&l1,&l2);
        ListNode *p=l;
        while(l1||l2){
            p->next=nextNode(&l1,&l2);
            p=p->next;
        }
        
        return l;
    }
};
