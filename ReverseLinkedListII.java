/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode sentinel = new ListNode(-1);
        sentinel.next=head;
        ListNode prev=sentinel,p=head;
        int cnt=1;
        for(cnt=2;cnt<=m;cnt++){
            prev=prev.next;
            p=p.next;
        }//p is the m th node
        ListNode nhead=p,forward=p.next,tail=p;
       for(cnt=1;cnt<=n-m;cnt++){
           p=forward;
           forward=forward.next;
           p.next=nhead;
           nhead=p;
       }
       prev.next=p;
       tail.next=forward;
       return sentinel.next;
    }
}
