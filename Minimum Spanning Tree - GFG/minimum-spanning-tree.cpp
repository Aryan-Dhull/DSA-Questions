//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisJointSet{
    vector<int> rank,parent,size;
    
    public:
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

class Solution{
	public:
    int spanningTree(int V, vector<vector<int>> adj[]){
        vector<pair<int,pair<int,int>>> edges;
        
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                int adjnode=it[0];
                int weight=it[1];
                int node=i;
                
                edges.push_back({weight,{node,adjnode}});
            }   
        }
        
        sort(edges.begin(),edges.end());
        
        int mstWt=0;
        
        DisJointSet ds(V);
        
        for(auto it: edges){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            
            if(ds.findUpar(u)!=ds.findUpar(v)){
                mstWt+=wt;
                ds.unionBySize(u,v);
            }
        }
        
        return mstWt;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends