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
    public boolean inArray(int n,int[] nums){
        for(int i:nums){
            if(i==n){
                return true;
            }
        }
        return false;
    }
    public int numComponents(ListNode head, int[] nums) {
        ListNode temp=head;
        int count=0;
        while(temp!=null){
            ListNode ptr=temp;
            int f=0;
            while(inArray(ptr.val,nums)){
                f=1;
                if(ptr.next==null){
                    break;
                }
                ptr=ptr.next;
            }
            if(f==1){
                count+=1;
            }
            temp=ptr.next;
        }
        return count;
    }
}