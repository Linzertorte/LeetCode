class Solution {
public:
   void print(ListNode *head){
       if(!head){
           cout<<endl;
           return;
       }
       cout<<" "<<head->val;
       print(head->next);
   }
   int get_length(ListNode *head){
       int cnt=0;
       while(head) cnt++,head=head->next;
       return cnt;
   }
   ListNode *reverseKGroup(ListNode *head, int k) {
       ListNode *h=NULL,*t,*gh,*gt,*prev;
       ListNode *p=head;
       int len=get_length(head);
       int groups=len/k;
       while(p){
           gh=p;
           gt=p;
           p=p->next;
           if(groups)
           for(int i=1;i<k;i++)
               prev=p,p=p->next,prev->next=gh,gh=prev;
           if(!h) h=gh,t=gt;
           else t->next=gh,t=gt;
           if(groups)groups--;
           if(!groups) break;
       }
       t->next=p;
       return h;
   }
};
