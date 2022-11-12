class Solution {
    public int minimumDeletions(int[] nums) {
        int min_index=0;
        int max_index=0;
        int min=Integer.MAX_VALUE;
        int max=Integer.MIN_VALUE;
        for(int i=0;i<nums.length;i++){
            if(nums[i]>max){
                max=nums[i];
                max_index=i;
            }
            if(nums[i]<min){
                min=nums[i];
                min_index=i;
            }
        }
        int l_deletions=Math.max(min_index,max_index)+1;
        int r_deletions=nums.length-Math.min(min_index,max_index);
        int b_deletions=Math.min(min_index,max_index)+1+nums.length-Math.max(min_index,max_index);
        return Math.min(b_deletions,Math.min(l_deletions,r_deletions));
    }
}