//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisJointSet{
    public:
        vector<int> rank,parent,size;
        DisJointSet(int n){
            rank.resize(n+1,0);
            size.resize(n+1,1);
            parent.resize(n+1);
            
            for(int i=0;i<=n;i++)parent[i]=i;
        }
        
        int findUpar(int u){
            if(u==parent[u])return u;
            else return parent[u]=findUpar(parent[u]);
        }
        
        void unionBySize(int u,int v){
            int up_u=findUpar(u);
            int up_v=findUpar(v);
            
            if(up_u==up_v)return;
            
            if(size[up_u]>size[up_v]){
                parent[up_v]=up_u;
                size[up_u]+=size[up_v];
            }
            
            else{
                parent[up_u]=up_v;
                size[up_v]+=size[up_u];
            }
        }
        
        void unionByRank(int u,int v){
            int up_u=findUpar(u);
            int up_v=findUpar(v);

            if(up_u==up_v)return;
            
            if(rank[up_u]>rank[up_v]){
                parent[up_v]=up_u;
            }
            
            else if(rank[up_v]>rank[up_u]){
                parent[up_u]=up_v;
            }
            
            else{
                parent[up_u]=up_v;
                rank[up_v]++;
            }
        }
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        DisJointSet ds(n);
        
        int cntextra=0;
        
        for(auto it: edge){
            int u=it[0];
            int v=it[1];
            if(ds.findUpar(u)==ds.findUpar(v))cntextra++;
            else ds.unionBySize(u,v);
        }
        
        int connC=0;
        
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i)connC++;
        }
        
        int ans=connC-1;
        
        if(cntextra>=ans)return ans;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends