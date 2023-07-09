//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
        bool dfs(int start,vector<int> graph[], vector<int> &vis,vector<int> &pathvis,vector<int> &check){
            vis[start]=1;
            pathvis[start]=1;
            check[start]=0;
            // int m=graph[start].size();
            // cout<<start<<endl;
            for(auto it: graph[start]){
                // cout<<start<<" "<<graph[start][i]<<endl;
                if(!vis[it]){
                    if(dfs(it,graph,vis,pathvis,check)==true){
                        check[start]=0;
                        return true;
                    }
                }
                else if(pathvis[it]){
                    check[start]=0;
                    return true;
                }
            }
            check[start]=1;
            pathvis[start]=0;
            return false;
        }
        
        
    public:
        vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
            vector<int> ans;
            vector<int> vis(n,0);
            vector<int> pathvis(n,0);
            vector<int> check(n,0);
            for(int i=0;i<n;i++){
                if(!vis[i])dfs(i,adj,vis,pathvis,check);
            }
    
            for(int i=0;i<n;i++){
                if(check[i])ans.push_back(i);
            }
            return ans;
        }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends