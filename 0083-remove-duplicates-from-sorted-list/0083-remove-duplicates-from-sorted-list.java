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
    public ListNode deleteDuplicates(ListNode head) {
        if(head!=null) {
            ListNode temp = head;
            while (temp.next != null) {
                if (temp.val == temp.next.val ) {
                    if(temp.next.next!=null) {
                        temp.next = temp.next.next;
                    }
                    else{
                        temp.next=null;
                    }
                }
                else {
                    temp = temp.next;
                }
            }
            return head;
        }
        else{
            return null;
        }
    }
}