// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    bool dfs(int root, vector<int> &vis, vector<int> adj[], int dest)
    {
        vis[root] = 1;
        if(root == dest)
            return true;
        for(auto it: adj[root])
        {
            if(!vis[it])
            {
                if(dfs(it,vis,adj,dest) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
    int celebrity(vector<vector<int> >& grid, int n) {
        // code here
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(i!=j && grid[i][j] == 1)
                {
                    adj[i].push_back(j);
                }
            }
        }
        // for(auto it: grid)
        // {
        //     for(auto itr: it)
        //         cout<<itr<<" ";
        //     cout<<endl;
        // }
        vector<int> potential;
        for(int i=0;i<n;i++)
        {
            if(adj[i].size()==0)
                potential.push_back(i);
        }
        for(int i=0;i<potential.size();i++)
        {
            int x = potential[i];
            int flag = 0;
            for(int j = 0;j<n;j++)
            {
                if(x!=j && grid[j][x]!=1)
                {
                    flag = 1;
                    break;
                }
            }
            if(!flag)
                return x;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
}

// } Driver Code Ends