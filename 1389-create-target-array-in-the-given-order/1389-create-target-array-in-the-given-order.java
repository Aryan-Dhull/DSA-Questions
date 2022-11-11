class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        int[] target = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            if (index[i] == i) {
                target[i] = nums[i];
            } else {
                for (int j = i; j > index[i]; j--) {
                    target[j] = target[j - 1];
                }
                target[index[i]] = nums[i];
            }
        }
        return target;
    }
}