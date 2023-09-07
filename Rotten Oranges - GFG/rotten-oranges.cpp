//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
         queue<pair<int,int>> q;
        int fresh=0;
    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==2)q.push({i,j});
                else if(arr[i][j]==1)fresh++;
            }
        }
    
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
    
        int time=0;
        while(!q.empty() && fresh!=0){
            int s=q.size();
            for(int t=0;t<s;t++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
    
                for(int i=0;i<4;i++){
                    for(int j=0;j<4;j++){
                        int nx=x+dx[i];
                        int ny=y+dy[i];
                        if(nx>=0 && nx<n && ny>=0 && ny<m && arr[nx][ny]==1){
                            arr[nx][ny]=2;
                            fresh--;
                            q.push({nx,ny});
                        }
                    }
                }
            }
            time++;
        }
    
        if(fresh!=0)return -1;
        else return time;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends