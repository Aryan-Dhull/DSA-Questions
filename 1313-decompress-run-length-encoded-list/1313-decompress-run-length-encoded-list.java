class Solution {
    public int[] decompressRLElist(int[] nums) {
        ArrayList<Integer> arr=new ArrayList<>();
        Map<Integer , Integer> freq=new HashMap<>();
        for(int i=1;i< nums.length+1;i=i+2){
            freq.put(nums[i],nums[i-1]);
            for(int j=0;j<freq.get(nums[i]);j++){
                arr.add(nums[i]);
            }
        }
        int l=arr.size();
        int[] arr2=new int[l];
        for(int i=0;i<l;i++){
            arr2[i]=arr.get(i);
        }
        return arr2;
    }
}