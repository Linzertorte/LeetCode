
class Solution {
public:
    int get_length(ListNode *head){
        int cnt=0;
        while(head) cnt++,head=head->next;
        return cnt;
    }
    void reorderList(ListNode *head) {
        int len=get_length(head);
        if(len<=1) return;
        int half=len/2;
      //  cout<<"half"<<half<<endl;
        ListNode *p,*prev;
        p=head;
        for(int i=0;i<half;i++) prev=p,p=p->next;
        prev->next=NULL;
        //two list now, head, and p
        //reverse p
        //merge head and p
        ListNode *nh=p;
        prev=p,p=p->next;
        prev->next=NULL;
        while(p){
            prev=p,p=p->next;
            prev->next=nh;
            nh=prev;
        }
        //print(nh);
        // print(head);
        
        
        //cout<<"goo"<<endl;
        ListNode *p1=head->next,*p2=nh->next;
        head->next=nh,p=nh;
        while(p1){
            p->next=p1,p1=p1->next;
            p=p->next;
            p->next=p2,p2=p2->next;
            p=p->next;
        }
        if(p2) p->next=p2,p=p->next,p->next=NULL;
    }
    void print(ListNode *head){
        if(!head){
            cout<<endl;
            return;
        }
        cout<<" "<<head->val;
        print(head->next);
    }
};
