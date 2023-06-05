//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<int> Stack;
        for(auto i:x){
            if(i=='(' || i=='[' || i=='{')Stack.push(i);
            else{
                if(Stack.empty()) return false;
                char ch=Stack.top();
                Stack.pop();
                if((ch=='(' && i==')') || (ch=='[' && i==']') || (ch=='{' && i=='}')) continue;
                else return false;
            }
        }
        return Stack.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends