// https://leetcode.com/problems/unique-paths/description/

class Solution {
public:
    int solve(int m,int n, vector<vector<int>> &dp)
    {
        if(m==0 || n==0)
            return 1;
        if(m<0 || n<0)
            return 0;
        if(dp[m][n]!=-1)
            return dp[m][n];
        int up = solve(m,n-1,dp);
        int left = solve(m-1,n,dp);
        return dp[m][n] = up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        for(int i=0;i<n;i++)
            dp[0][i] = 1;
        for(int i=0;i<m;i++)
            dp[i][0] = 1;
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                int right = dp[i][j-1];
                int down = dp[i-1][j];
                dp[i][j] = right+down;
            }
        }
        return dp[m-1][n-1];
    }
};