// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void solve(int root, vector<int> adj[], vector<int> &dfs, vector<int> &vis)
    {
        vis[root] = 1;
        dfs.push_back(root);
        for(auto it: adj[root])
        {
            if(!vis[it])
            {
                vis[it] = 1;
                solve(it,adj,dfs,vis);
            }
        }
        return ;
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> dfs;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                solve(i,adj,dfs,vis);
            }
        }
        return dfs;
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends