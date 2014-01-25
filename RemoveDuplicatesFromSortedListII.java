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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode sentinel = new ListNode(-1);
        sentinel.next=head;
        ListNode prev,p,forward;
        int cnt=0;
        prev=sentinel;
        p=head;
        forward=head;
        while(p!=null){
            while(forward!=null && forward.val==p.val)
            {
                forward=forward.next;
                cnt++;
            }
            if(cnt==1) prev=prev.next;
            else //remove duplicates
                prev.next=forward;
            
            cnt=0;
            p=forward;
        }
        return sentinel.next;
    }
}
