// https://www.geeksforgeeks.org/problems/bipartite-graph/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int root, vector<int> adj[], vector<int> &vis,vector<int> &color,int col)
    {
        vis[root] = 1;
        color[root] = col;
        for(auto it: adj[root])
        {
            if(!vis[it])
            {
                if(dfs(it,adj,vis,color,!col)==false)
                    return false;
            }
            else if(color[it]==col)
            {
                return false;
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> vis(V,0);
	    vector<int> color(V,0);
	    for(int i=0;i<V;i++)
	    {   
	        if(!vis[i])
	        {
	            if(dfs(i,adj,vis,color,0)==false)
	                return false;
	        }
	        
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends