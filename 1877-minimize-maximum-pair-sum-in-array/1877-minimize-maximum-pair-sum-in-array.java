import java.util.Arrays;
class Solution {
    public int minPairSum(int[] nums) {
        Arrays.sort(nums);
        int max=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]+nums[nums.length-1-i]>max){
                max=nums[i]+nums[nums.length-i-1];
            }
        }
        return max;
    }
}