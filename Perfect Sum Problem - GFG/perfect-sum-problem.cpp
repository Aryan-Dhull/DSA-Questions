//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
private:
    int f(int ind, int k, int arr[],vector<vector<int>>& dp) {
        if(ind==0){
            if(k==0 && arr[0]==0)return 2;
            else if(k==0 || arr[0]==k)return 1;
            else return 0;
        }
        if(dp[ind][k]!=-1)return (dp[ind][k])%1000000007;
        int notpick=(f(ind-1,k,arr,dp))%1000000007;
        int pick=0;
        if(arr[ind]<=k)pick=(f(ind-1,k-arr[ind],arr,dp))%1000000007;
        return dp[ind][k]=(pick%1000000007)+(notpick%1000000007);
    }

public:
	int perfectSum(int num[], int n, int k){
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return f(n-1,k,num,dp)%1000000007;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends