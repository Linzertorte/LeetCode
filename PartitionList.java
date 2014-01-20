public class Solution {
    public void print(ListNode head){
        if(head==null) return;
        System.out.println(head.val);
        print(head.next);
    }
    public ListNode partition(ListNode head, int x) {
        ListNode sentinel = new ListNode(-1);
        sentinel.next=head;
        ListNode p,prev,d;
        ListNode cur=sentinel;
        prev=sentinel;
        p=head;
        while(p!=null){
            if(p.val<x){
                if(cur==prev){
                    cur=cur.next;
                    prev=prev.next;
                    p=p.next;
                }
                else{
                    prev.next=p.next;
                    d=p;
                    p=p.next;
                    //insert d after cur
                    d.next=cur.next;
                    cur.next=d;
                    cur=cur.next;
                }
                
            }else{
                p=p.next;
                prev=prev.next;
            }
        }
        return sentinel.next;
    }
}
