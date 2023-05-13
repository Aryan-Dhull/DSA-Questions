//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long X) {
        int binaryNum[32]={0};

        int i=0;
        while(X>0){
            binaryNum[i]=X%2;
            X/=2;
            i++;
        }

        long long ans=0;
        long long base=1;
        long long t=31;
        while(t>=0){
            long long last=binaryNum[t];
            ans+=last*base;
            base*=2;
            t--;
        }      

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends