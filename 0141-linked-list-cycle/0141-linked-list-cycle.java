/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        while(head!=null){
            head.val=Integer.MIN_VALUE;
            if(head.next!=null) {
                if (head.next.val == Integer.MIN_VALUE) {
                    return true;
                } else {
                    head = head.next;
                }
            }
            else{
                return false;
            }
        }
        return false;
    }
}
