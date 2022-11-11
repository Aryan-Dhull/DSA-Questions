class Solution {
    public static int binarysearch(int[] a,int l,int h){
        if(l>h){
            return -1;
        }
        int mid=(l+h)/2;
        if(a[mid]>a[mid+1] && a[mid]>a[mid-1]){
            return mid;
        }
        else if(a[mid]<a[mid+1]){
            return binarysearch(a,mid+1,h);
        }
        else{
            return binarysearch(a,l,mid-1);
        }
    }
    public static int peakIndexInMountainArray(int[] arr) {
        return binarysearch(arr,0,arr.length);
    }
}