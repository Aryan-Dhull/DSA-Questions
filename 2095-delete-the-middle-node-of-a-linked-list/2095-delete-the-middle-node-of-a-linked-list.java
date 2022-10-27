/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteMiddle(ListNode head) {
        if(head!=null && head.next!=null){
            ListNode ptr = head;
            int s = 0;
            while (ptr != null) {
                s++;
                ptr = ptr.next;
            }
            ptr=head;
            int i=0;
            while(ptr!=null){
                if(i==(s/2)-1){
                    ptr.next=ptr.next.next;
                }
                else{
                    ptr=ptr.next;
                }
                i++;
            }
            return head;
        }
        return null;
    }
}