import java.util.*;
class Solution {
    public int partitionArray(int[] nums, int k) {
        int answer=0;
        Arrays.sort(nums);
        int i=1,j=0;
        while(j<nums.length) {
            while (i < nums.length && nums[i] <= (k + nums[j])) {i++;}
            answer += 1;
            j = i;
        }
        return answer;
    }
}