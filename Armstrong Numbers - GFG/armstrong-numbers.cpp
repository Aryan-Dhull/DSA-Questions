//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n){
        int t=n;
        int c=0;
        while(t>0){
            t=t/10;
            c++;
        }

        int num=0;
        int u=n;
        while(u>0){
            int d=u%10;
            num+=pow(d,c);
            u=u/10;
        }

        if(num==n){return "Yes";}
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends