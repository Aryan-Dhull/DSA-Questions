class Solution {
    public boolean containsDuplicate(int[] arr) {
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i <arr.length; i++) {
            if (mp.containsKey(arr[i])) {
                return true;
            } else {
                mp.put(arr[i], 1);
            }
        }
        return false;
    }
}