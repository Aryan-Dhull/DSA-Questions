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
    public ListNode swapNodes(ListNode head, int k) {
        if(head!=null) {
            ListNode ptr = head, ptr2 = head;
            int s = 0;
            while (ptr != null) {
                s++;
                ptr = ptr.next;
            }
            int f = k - 1;
            int l = s - k;
            ptr = head;
            int i = 0;
            while (i != f) {
                ptr = ptr.next;
                i++;
            }
            int j = 0;
            while (j != l) {
                ptr2 = ptr2.next;
                j++;
            }
            int t = ptr.val;
            ptr.val = ptr2.val;
            ptr2.val = t;
            return head;
        }
        return null;
    }
}