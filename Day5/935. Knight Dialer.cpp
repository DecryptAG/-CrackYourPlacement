// https://leetcode.com/problems/knight-dialer/description/

const int M = 1e9+7;
class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &grid, int x,vector<vector<vector<int>>> &dp)
    {
        int n = grid.size(); 
        int m = grid[0].size();
        if(x==0)
            return 1;
        if(dp[i][j][x]!=-1)
            return dp[i][j][x];
        int ver[] = {2, 2, -2, -2, 1, -1, 1, -1};
        int hor[] = {1, -1, 1, -1, 2, 2, -2, -2};
        int pick = 0;
        for(int k=0;k<8;k++)
        {
            int r = i + ver[k];
            int c = j + hor[k];
            if(r<n && r>=0 && c<m && c>=0 && grid[r][c]!=15 && x>0)
            {
                pick= pick%M + solve(r,c,grid,x-1,dp)%M;
            }
        }
        return dp[i][j][x] = pick%M;
    }
    int knightDialer(int n) {
        vector<vector<int>> grid(4,vector<int>(3));
        int temp = 1;
        for(int i=0;i<4;i++)
        {
            for(int j =0 ;j<3;j++)
            {
                grid[i][j] = temp;
                temp++;
            }
        }
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(3, vector<int>(n,-1)));
        grid[3][0] = 15, grid[3][2] = 15;
        int ans = 0;
        for(int i=0;i<4;i++)
        {
            for(int j =0 ;j<3;j++)
            {
                if(grid[i][j]!=15)
                {
                    ans = ans%M + solve(i,j,grid,n-1,dp)%M;
                }
            }
        }
        return ans%M;
    }
};

