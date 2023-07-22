//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
private:
    int f(int i,int pi,int n,int arr[],vector<vector<int>> &dp){
        if(i>=n)return 0;
        if(dp[i][pi+1]!=-1)return dp[i][pi+1];
        int notpick=f(i+1,pi,n,arr,dp);
        int pick=0;
        if(pi==-1 || arr[i]>arr[pi])pick+=arr[i]+f(i+1,i,n,arr,dp);
        return dp[i][pi+1]=max(pick,notpick);
    }
public:
	int maxSumIS(int arr[], int n)  {
	    vector<vector<int>> dp(n,vector<int>(n+1,-1));
	    return f(0,-1,n,arr,dp);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends