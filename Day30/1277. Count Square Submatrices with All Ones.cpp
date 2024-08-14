// https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/

class Solution {
public:
    int n,m;
    int solve(int i,int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if(i>=n || j>=m)
            return 0;
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int right = 0,down = 0,diag = 0;
        right  = solve(i,j+1,matrix,dp);
        down = solve(i+1,j,matrix,dp);
        diag = solve(i+1,j+1,matrix,dp);

        if(matrix[i][j] == 1)
        {
            return dp[i][j] = 1 + min(right,min(down,diag));
        }
        return dp[i][j] = 0;
    }
    int countSquares(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        solve(0,0,matrix,dp);
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {   
                if(dp[i][j]!=0)
                {   
                    
                    ans+=dp[i][j];
                }
            }
            cout<<endl;
        }
        return ans;
    }
};