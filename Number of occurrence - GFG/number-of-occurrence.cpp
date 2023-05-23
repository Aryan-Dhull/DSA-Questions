//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int nums[], int n, int target) {
	    // code here
            int start=0;
            int end=0;
            
            int low = 0;
            int high = n - 1;
            while (low < high)
            {
                int mid = (low + high) / 2;
                if (nums[mid] < target) low = mid + 1;
                else high = mid;
            }
            if (nums[low] != target) return 0;
            start=low;

            high = n - 1;
            while (low < high)
            {
                int mid = (low + high) / 2 + 1;
                if (nums[mid] > target) high = mid - 1;
                else low = mid;
            }
            end = high;
            return end-start+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends