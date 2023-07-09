class Solution {
private:
    // bool dfs(int start,vector<vector<int>> &graph,vector<int> &vis){
    //     vis[start]=1;
    //     int m=graph[start].size();
    //     if(m==0)return true;
    //     for(int i=0;i<m;i++){
    //         if(vis[graph[start][i]] || dfs(graph[start][i],graph,vis)==false)return false;
    //     }
    //     return true;
    // }

    bool dfs(int start,vector<vector<int>>& graph, vector<int> &vis,vector<int> &pathvis,vector<int> &check){
        vis[start]=1;
        pathvis[start]=1;
        check[start]=0;
        int m=graph[start].size();
        cout<<start<<endl;
        for(int i=0;i<m;i++){
            cout<<start<<" "<<graph[start][i]<<endl;
            if(!vis[graph[start][i]]){
                if(dfs(graph[start][i],graph,vis,pathvis,check)==true)return true;
            }
            else if(pathvis[graph[start][i]])return true;
            
        }
        pathvis[start]=0;
        check[start]=1;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> ans;
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        vector<int> check(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i])dfs(i,graph,vis,pathvis,check);
        }

        for(int i=0;i<n;i++){
            if(check[i])ans.push_back(i);
        }
        return ans;
    }
};