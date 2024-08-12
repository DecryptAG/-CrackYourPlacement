// https://www.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long solve(int i,int j, int n,vector<vector<int>> &grid,vector<vector<vector<long long>>> &dp){
        if(n<=1)
            return 1;
        int x = grid.size();
        int y = grid[0].size();
        if(dp[i][j][n]!=-1)
            return dp[i][j][n];
        int drow[] = {+1,0,0,-1};
        int dcol[] = {0,-1,+1,0};
        long long count = 0;
        count+=solve(i,j,n-1,grid,dp);
        for(int k = 0;k<4;k++)
        {
            int r = i + drow[k];
            int c = j + dcol[k];
            if(r>=0 && r<x && c>=0 && c<y && grid[r][c]!=15)
            {
               count+=solve(r,c,n-1,grid,dp);
            }
        }
        return dp[i][j][n] = count;
    }
    long long getCount(int n) {
        vector<vector<int>> grid(4,vector<int>(3,0));
        int a = 1;
        for(int i=0;i<3;i++)
        {
            for(int j = 1;j<3;j++)
            {
                grid[i][j] = a;
                a++;
            }
        }
        grid[3][0] = 15;
        grid[3][1] = 0;
        grid[3][2] = 15;
        vector<vector<vector<long long>>> dp(4,vector<vector<long long>>(3,vector<long long>(n+1,-1)));
        long long ans = 0;
        for(int i=0;i<4;i++)
        {
            for(int j = 0;j<3;j++)
            {   
                if(grid[i][j]!=15)
                {   
                    long long z = solve(i,j,n,grid,dp);
                    // cout<<grid[i][j]<<" "<<z<<endl;
                    ans+=z;
                }
                    
            }
        }
        return ans;
        // Your code goes here
        
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends