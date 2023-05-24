//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int nums[], int n , int x )
{
    // code here
    vector<int> ans;
    ans.push_back(-1);
    ans.push_back(-1);
            
    int low = 0;
    int high = n - 1;
    while (low < high){
        int mid = (low + high) / 2;
        if (nums[mid] < x) low = mid + 1;
        else high = mid;
    }
    if (nums[low] != x) return ans;
    else ans[0] = low;

    high = n - 1;
    while (low < high){
        int mid = (low + high) / 2 + 1;
        if (nums[mid] > x) high = mid - 1;
        else low = mid;
    }
    ans[1] = high;

    return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends