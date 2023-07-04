//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

bool comp(string &s1, string &s2) {
        return s1.size() < s2.size();
    }
    
class Solution {
private:
    bool checkpossible(string &s1, string &s2) {
        if(s1.size()!=s2.size()+1)return false;
        int f=0;
        int s=0;
    
        while (f < s1.size()) {
            if(s<s2.size() && s1[f]==s2[s]){
                s++;
                f++;
            }
            else{
                f++;
            }
        }
    
        if(f==s1.size() && s==s2.size())return true;
        return false;
    }
    
public:

    
    int longestChain(int n, vector<string>& arr) {
        sort(arr.begin(),arr.end(),comp);
    
        vector<int> dp(n,1);
        int maxi=1;
    
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(checkpossible(arr[i],arr[prev]) && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                }
            }
            if(dp[i]>maxi)maxi=dp[i];
        }
    
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends