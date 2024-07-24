// https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(int i, int j, int n, int m, vector<vector<char>> &mat)
    {
        mat[i][j] = '*';
        int drow[] = {+1,0,0,-1};
        int dcol[] = {0,-1,+1,0};
        for(int k=0;k<4;k++)
        {
            int r = i + drow[k];
            int c = j + dcol[k];
            if(r>=0 && r<n && c>=0 && c<m && mat[r][c] =='O')
            {
                dfs(r,c,n,m,mat);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        
        for(int i=0;i<m;i++)
        {
            if(mat[0][i] == 'O')
            {
                dfs(0,i,n,m,mat);
            }
            if(mat[n-1][i] == 'O')
            {
                dfs(n-1,i,n,m,mat);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(mat[i][0] == 'O')
            {
                dfs(i,0,n,m,mat);
            }
            if(mat[i][m-1] == 'O')
            {
                dfs(i,m-1,n,m,mat);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(mat[i][j] == 'O')
                    mat[i][j] = 'X';
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(mat[i][j] == '*')
                {
                    mat[i][j] = 'O';
                }
            }
        }
        return mat;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends