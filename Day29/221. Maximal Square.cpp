// https://leetcode.com/problems/maximal-square/description/

class Solution {
public:
    int solve(int i, int j, vector<vector<char>> &matrix, vector<vector<int>> &dp)
    {   
        int n = matrix.size();
        int m = matrix[0].size();
        if(i>=n || j>=m)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int right = solve(i,j+1,matrix,dp);
        int down = solve(i+1,j,matrix,dp);
        int diag = solve(i+1,j+1,matrix,dp);

        if(matrix[i][j]=='1')
        {   
            int ans = 1 + min(right,min(down,diag));
            return dp[i][j] = ans;
        }
        return dp[i][j] = 0;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        solve(0,0,matrix,dp);
        int maxi = 0;
        for(int i=0;i<=n;i++)
        {
            for(int j = 0;j<=m;j++)
            {
                maxi = max(maxi,dp[i][j]);
            }
        }
        return maxi*maxi;
    }
};