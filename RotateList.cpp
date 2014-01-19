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
    static int len(ListNode *h){
        int ans=0;
        while(h) ans++,h=h->next;
        return ans;
    }
    ListNode *rotateRight(ListNode *head, int k) {
        int l=len(head);
        if(!l) return head;
        k=k%l;
        if(!k) return head;
        int forward =l-k;
     
        ListNode *p=head;
        ListNode *prev;
        for(int i=0;i<forward;i++) prev=p,p=p->next;
        prev->next=NULL;
        ListNode *q=p;
        for(int i=0;i<k-1;i++) q=q->next;
        q->next=head;
        
        return p;
        
        
    }
};
