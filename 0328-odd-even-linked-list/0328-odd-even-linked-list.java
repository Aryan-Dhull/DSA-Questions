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
    public ListNode oddEvenList(ListNode head) {
        ArrayList<Integer> arr=new ArrayList<>();
        ListNode ptr1=head;
        while(ptr1!=null){
            arr.add(ptr1.val);
            ptr1=ptr1.next;
        }
        ptr1=head;
        for(int i=0;i<arr.size();i+=2){
            ptr1.val= arr.get(i);
            ptr1=ptr1.next;
        }
        for(int i=1;i<arr.size();i+=2){
            ptr1.val= arr.get(i);
            ptr1=ptr1.next;
        }
        return head;
    }
}