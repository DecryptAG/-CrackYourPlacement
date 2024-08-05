// https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isValid(int node,vector<int> adj[],int n,int m,int col, vector<int> &color)
    {
        for(auto it: adj[node])
        {
            if(col == color[it])
                return false;
        }
        return true;
    }
    bool solve(int node,vector<int> adj[],vector<int> &color,int n,int m)
    {
        if(node == n)
            return true;
        for(int i=1;i<=m;i++)
        {
            if(isValid(node,adj,n,m,i,color))
            {
                color[node] = i;
                if(solve(node+1,adj,color,n,m) == true)
                    return true;
                color[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> adj[101];
        for(int i=0;i<101;i++)
        {   
            for(int j = 0;j<101;j++)
            {
                if(i!=j && graph[i][j] == 1)
                {
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> color(n,0);
        if(solve(0,adj,color,n,m) == true)
            return true;
        return false;
        // return solve(0,adj,color,n,m);
        // your code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends