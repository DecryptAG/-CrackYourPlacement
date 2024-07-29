// https://www.geeksforgeeks.org/problems/rotten-oranges2536/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n= grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int fresh = 0;
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    fresh++;
                }
                if(grid[i][j] == 2)
                {
                    q.push({0,{i,j}});
                    vis[i][j] = 1;
                }
            }
        }
        int ansT = 0;
        while(!q.empty())
        {
            int t = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            ansT = max(ansT,t);
            q.pop();
            int drow[] = {1,0,0,-1};
            int dcol[] = {0,-1,+1,0};
            for(int i = 0;i<4;i++)
            {
                int row = r + drow[i];
                int col = c + dcol[i];
                if(row>=0 && col>=0 && row<n && col<m && grid[row][col]==1 && !vis[row][col])
                {   
                    vis[row][col] = 1;
                    q.push({t+1,{row,col}});
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == 1 && vis[i][j] == 0)
                {
                    return -1;
                }
            }
        }
        return ansT;
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