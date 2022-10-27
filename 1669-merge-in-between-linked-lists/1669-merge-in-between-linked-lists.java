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
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode ptr=list1;
        ListNode ptr2=list1;
        ListNode ptr3=list2;
        int i=0;
        while(i!=a-1){
            ptr=ptr.next;
            i++;
        }
        int j=0;
        while(j!=b+1){
            ptr2=ptr2.next;
            j++;
        }
        while(ptr3!=null){
            ptr.next=ptr3;
            ptr=ptr.next;
            ptr3=ptr3.next;
        }
        while(ptr2!=null){
            ptr.next=ptr2;
            ptr=ptr.next;
            ptr2=ptr2.next;
        }
        return list1;
    }
}