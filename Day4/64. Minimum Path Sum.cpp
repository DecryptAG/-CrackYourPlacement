// https://leetcode.com/problems/minimum-path-sum/description/

class Solution {
public:
    int solve(int n,int m, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if(n==0 && m==0)
            return grid[n][m];
        if(n<0 || m<0)
            return 1e5;
        if(dp[n][m]!=-1)
            return dp[n][m];
        int left = grid[n][m] + solve(n,m-1,grid,dp);
        int up = grid[n][m] + solve(n-1,m,grid,dp);
        return dp[n][m] = min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {   
            for(int j = 0;j<m;j++)
            {
                if(i==0 && j==0)
                    dp[i][j] = grid[i][j];
                else
                {   
                    int right = 1e5, down = 1e5;
                    if(i>0)
                        down = grid[i][j] +  dp[i-1][j];
                    if(j>0)
                        right = grid[i][j] + dp[i][j-1];
                    dp[i][j] = min(down,right);
                }
            }
        }
        return dp[n-1][m-1];
    }
};