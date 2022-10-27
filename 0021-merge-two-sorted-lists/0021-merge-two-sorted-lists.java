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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        LinkedList<Integer> ll=new LinkedList<>();
        while(list1!=null){
            ll.add(list1.val);
            list1= list1.next;
        }
        while(list2!=null){
            ll.add(list2.val);
            list2=list2.next;
        }
        Collections.sort(ll);
        int l=ll.size();
        if(l>0) {
            ListNode head = new ListNode(ll.get(0));
            ListNode temp = head;
            for (int i = 1; i < l; i++) {
                temp.next = new ListNode(ll.get(i));
                temp = temp.next;
            }
            return head;
        }
        else{
            return null;
        }
    }
}