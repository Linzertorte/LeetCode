class Solution{

		public:
				ListNode* insert(ListNode *cur, ListNode *prev, ListNode **head){
					//	cout<<"head is"<<(*head)->val<<"prev is"<<(prev)->val<<"cur"<<cur->val<<endl;
						if(cur->val>=(prev)->val) {
					//			cout<<"nothing"<<endl;
								return cur; //alreay in order
						}
						//delete cur
						(prev)->next = cur->next;
						//insert in order
						ListNode *p;
						ListNode *p1;
						for(p=*head;p->val<=cur->val; p1=p,p=p->next);

						if(p==*head){
								//insert to head
								cur->next=*head;
								*head = cur;
								return prev;
						}
						//insert between p1 p
						
						cur->next=p;
						p1->next=cur;
					//	print(*head);
						return prev;

				}
				ListNode *insertionSortList(ListNode *head){
						if(!head) return head;
						ListNode *p1=head;
						ListNode *p=p1->next;
						ListNode *t;
						while(p){
				//				cout<<"inserting"<<p->val<<endl;
								t=p;
								p=p->next;
								p1=insert(t,p1,&head);
						}
						return head;  

				}
};
