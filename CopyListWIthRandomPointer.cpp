/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode *,RandomListNode *> deep;
        if(!head) return head;
        RandomListNode *p=new RandomListNode(head->label);
        RandomListNode *prev=p,*n;
        RandomListNode *newhead=p;

        deep[NULL]=NULL;
        deep[head]=p;
        p=head;
        while(p->next){
            p=p->next;
            n = new RandomListNode(p->label);
            deep[p]=n;
            prev->next=n;
            prev=prev->next;
        }
        p=head,n=newhead;
        while(p){
            n->random=deep[p->random];
            
            p=p->next;
            n=n->next;
        }
        return newhead;
        
    }
};
