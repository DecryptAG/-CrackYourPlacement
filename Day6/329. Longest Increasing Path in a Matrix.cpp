// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/

class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &matrix,vector<vector<int>> &dp)
    {   
        int n = matrix.size();
        int m = matrix[0].size();
        int drow[] = {+1,0,0,-1};
        int dcol[] = {0,-1,+1,0};
        int pick = 0;
        int f = 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        for(int k = 0; k<4;k++)
        {
            int r = i + drow[k];
            int c = j + dcol[k];
            if(r<n && r>=0 && c<m && c>=0 && matrix[r][c]>matrix[i][j])
            {   
                f=1;
                pick = max(pick,1 + solve(r,c,matrix,dp));
            }
                
        }
        if(!f)
            return 1;
        return dp[i][j] = pick;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0, maxi = 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j =0 ;j<m;j++)
            {
                ans = max(ans,solve(i,j,matrix,dp));
            }
        }
        return ans;
    }
};