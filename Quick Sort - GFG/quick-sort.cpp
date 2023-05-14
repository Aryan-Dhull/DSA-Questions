//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low<high){
            int par_index=partition(arr,low,high);
            quickSort(arr,low,par_index-1);
            quickSort(arr,par_index+1,high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int pivot=low;
       int i=low;
       int j=high;
       while(i<j){
           while(arr[i]<=arr[pivot] && i<high){i++;}
           while(arr[j]>arr[pivot] && j>low){j--;}
           if(i<j){
               int temp=arr[j];
               arr[j]=arr[i];
               arr[i]=temp;
           }
       }
       int temp=arr[j];
       arr[j]=arr[pivot];
       arr[pivot]=temp;
       return j;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends