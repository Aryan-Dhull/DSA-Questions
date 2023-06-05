//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int precedence(char c){
        if(c=='^')return 3;
        else if(c=='*' || c=='/')return 2;
        else if(c=='+' || c=='-')return 1;
        else return -1;
    }
    
    string infixToPostfix(string s) {
        
        stack<char> Stack;
        string result;
        
        for(auto i :s){
            if((i>='a' && i<='z') || (i>='A' && i<='Z') || (i>='0' && i<='9'))result+=i;
            
            else if(i=='(')Stack.push(i);
            
            else if(i==')'){
                while(Stack.top()!='('){
                    result+=Stack.top();
                    Stack.pop();
                }
                Stack.pop();
            }
            
            else{
                while(!Stack.empty() && precedence(Stack.top())>=precedence(i)){
                    result+=Stack.top();
                    Stack.pop();
                }
                Stack.push(i);
            }
        }
        
        while(!Stack.empty()){
            result+=Stack.top();
            Stack.pop();
        }
        
        return result;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends