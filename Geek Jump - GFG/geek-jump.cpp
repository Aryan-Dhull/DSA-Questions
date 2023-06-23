//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
//     int f(int ind,vector<int> &height){
//         if(ind==0)return 0;
//         int one=f(ind-1,height)+abs(height[ind]-height[ind-1]);
//         int two=INT_MAX;
//         if(ind>1)two=f(ind-2,height)+abs(height[ind]-height[ind-2]);
//         return min(one,two);
//     }
    int f(int ind,vector<int> &height,vector<int> &dp){
        if(ind==0)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int one=f(ind-1,height,dp)+abs(height[ind]-height[ind-1]);
        int two=INT_MAX;
        if(ind>1)two=f(ind-2,height,dp)+abs(height[ind]-height[ind-2]);
        return dp[ind]=min(one,two);
    }
  public:
    // int minimumEnergy(vector<int>& height, int n) {
    //     return f(n-1,height);
    // }
    
    int minimumEnergy(vector<int>&height,int n){
        vector<int> dp(n+1,-1);
        return f(n-1,height,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends