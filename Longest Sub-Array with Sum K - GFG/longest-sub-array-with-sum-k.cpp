//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int N, int K) 
    { 
            map<int,int> preSumMap;
            int sum=0;
            int max_len=0;
            for(int i=0;i<N;i++){
                sum+=arr[i];
                
                if(sum==K){
                    max_len=max(max_len,i+1);
                }
                
                int rem=sum-K;
                
                if(preSumMap.find(rem)!=preSumMap.end()){
                    int len=i-preSumMap[rem];
                    max_len=max(max_len,len);
                }
                
                if(preSumMap.find(sum)==preSumMap.end()){
                    preSumMap[sum]=i;
                }
            }
            return max_len;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends