//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
        //complete the function here
        int l=0;
        int h=n-1;
        int minVal=INT_MAX;
        
        while(l<=h){
            
            if(arr[l]<arr[h]){
                minVal=min(minVal,arr[l]);
                break;
            }
            
            int mid=(l+h)/2;
            
            if(arr[l]<=arr[mid]){
                minVal=min(arr[l],minVal);
                l=mid+1;
            }
            else{
                minVal=min(arr[mid],minVal);
                h=mid-1;
            }
            
        }
        return minVal;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends