class Solution {
    public int[] rearrangeArray(int[] nums) {
        int l=nums.length;
        int[] even=new int[l/2];
        int[] odd =new int[l/2];
        int e=0,o=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]<0){odd[o++]=nums[i];}
            else{even[e++]=nums[i];}
        }
        e=0;
        o=0;
        for(int i=0;i<nums.length;i++){
            if(i%2==0){
                nums[i]=even[e++];
            }
            else{
                nums[i]=odd[o++];
            }
        }
        return nums;
    }
}