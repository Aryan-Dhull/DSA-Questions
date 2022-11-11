class Solution {
    public int minOperations(int n) {
        int sum=0;
        for(int i=1;i<n;i+=2){
            sum+=(n-i);
        }
        return sum;
    }
}