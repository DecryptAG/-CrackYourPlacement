// https://leetcode.com/problems/number-of-islands/description/

class Solution {
public:
    void dfsCheck(int row, int col, vector<vector<int>>& vis, vector<vector<char>> &grid)
    {   
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        int drow[] = {+1,0,0,-1};
        int dcol[] = {0,-1,+1,0};
        for(int i=0;i<4;i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow<n && ncol<m && nrow>=0 && ncol>=0 && !vis[nrow][ncol] && grid[nrow][ncol]=='1')
            {
                dfsCheck(nrow,ncol,vis,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int count = 0;
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {   
                    // cout<<i<<j<<endl;
                    count++;
                    dfsCheck(i,j,vis,grid);
                }
            }
        }
        return count;
    }
};