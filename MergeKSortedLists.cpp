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
    bool check_terminated(vector<ListNode *> &lists){
        for(int i=0;i<lists.size();i++)
            if(lists[i]) return false;
        return true;
    }
    ListNode *getMin(vector<ListNode *> &lists){
        int m=INT_MAX;
        int idx;
        for(int i=0;i<lists.size();i++){
            if(lists[i] && lists[i]->val<m) m=lists[i]->val,idx=i;
        }
        ListNode *p=lists[idx];
        lists[idx]=lists[idx]->next;
        return p;
    }
    
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *p=NULL;
        ListNode *head=NULL;
        while(!check_terminated(lists)) {
            if(!p) head=p=getMin(lists);
            else p->next=getMin(lists),p=p->next;
        }
        if(p)p->next=NULL;
        return head;
    }
};
