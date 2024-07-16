// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int i, int j, vector<vector<int>> &m ,int n, string path, vector<string> &ans, vector<vector<int>> &vis)
    {
        if(i==n-1 && j==n-1)
        {
            ans.push_back(path);
            return;
        }
        vis[i][j] = 1;
        int drow[] = { +1,0,0,-1};
        int dcol[] = {0,-1,+1,0};
        for(int k = 0;k<4;k++)
        {
            int r = i + drow[k];
            int c = j + dcol[k];
            if(r>=0 && r<n && c>=0 && c<n && m[r][c]==1 && vis[r][c]!=1)
            {
                vis[r][c] = 1;
                if(k==0)
                    path.push_back('D');
                else if(k==1)
                    path.push_back('L');
                else if(k==2)
                    path.push_back('R');
                else
                    path.push_back('U');
                
                solve(r,c,m,n,path,ans,vis);
                
                path.pop_back();
                vis[r][c] = 0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0] == 0 || m[n-1][n-1]==0)
            return {};
        vector<string> ans;
        string path = "";
        vector<vector<int>> vis(n,vector<int>(n,0));
        solve(0,0,m,n,path, ans,vis);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends