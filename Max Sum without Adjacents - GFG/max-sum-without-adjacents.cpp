//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
private:
    int f(int* arr,int n){
        int prev=arr[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int pick=arr[i];
            if(i>1)pick+=prev2;
            int notpick=prev;
            int curi=max(pick,notpick);
            prev2=prev;
            prev=curi;
        }
        return prev;
    }
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    return f(arr,n);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends