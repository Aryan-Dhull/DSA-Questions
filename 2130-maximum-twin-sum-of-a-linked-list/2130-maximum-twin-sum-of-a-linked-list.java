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
    public int pairSum(ListNode head) {
        ArrayList<Integer> arr=new ArrayList<>();
        int max=0;
        ListNode ptr=head;
        while(ptr!=null){
            arr.add(ptr.val);
            ptr=ptr.next;
        }
        for(int i=0;i<arr.size()/2;i++){
            int sum=arr.get(i)+ arr.get(arr.size()-1-i);
            if(sum>max){
                max=sum;
            }
        }
        return max;
    }
}