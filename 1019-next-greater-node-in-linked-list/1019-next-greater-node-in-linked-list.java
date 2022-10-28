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
    public int[] nextLargerNodes(ListNode head) {
        ListNode ptr=head;
        ArrayList<Integer> A=new ArrayList<>();
        while(ptr!=null){
            A.add(ptr.val);
            ptr=ptr.next;
        }
        int[] arr=new int[A.size()];
        ptr=head;
        int i=1;
        while(ptr!=null){
            int max=0;
            for(int j=i;j<A.size();j++) {
                if (ptr.val < A.get(j) && max<A.get(j)) {
                    max = A.get(j);
                    break;
                }
            }
            arr[i-1]=max;
            i++;
            ptr=ptr.next;
        }
        return arr;
    }
}