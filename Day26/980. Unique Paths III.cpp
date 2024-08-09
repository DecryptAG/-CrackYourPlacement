// https://leetcode.com/problems/unique-paths-iii/description/

class Solution {
public:
    int n,m;
    int count = 0;
    int solve(int i, int j,int rEnd,int cEnd, vector<vector<int>> &vis, vector<vector<int>> &grid)
    {
        if(i==rEnd && j == cEnd)
        {
            for(int x=0;x<n;x++)
            {
                for(int y=0;y<m;y++)
                {
                    if(vis[x][y] != 1)
                        return 0;
                }
            }
            return 1;
        }
            
        int drow[] = {+1,0,0,-1};
        int dcol[] = {0,-1,+1,0};
        for(int k=0;k<4;k++)
        {
            int r = i + drow[k];
            int c = j + dcol[k];
            if(r<n && r>=0 && c<m && c>=0 && grid[r][c] != -1 && vis[r][c]==0)
            {   
                // cout<<"afsd"<<endl;
                vis[r][c] = 1;
                int x = solve(r,c,rEnd,cEnd,vis,grid);
                // cout<<x<<endl;
                count+=x;
                vis[r][c] = 0;
            }
        }
        return 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int rStart,cStart,rEnd,cEnd;
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {   
                if(grid[i][j] == -1)
                    vis[i][j] = 1;
                if(grid[i][j] == 1)
                {   
                    vis[i][j] = 1;
                    rStart = i;
                    cStart = j;
                }
                if(grid[i][j] == 2)
                {
                    rEnd = i;
                    cEnd = j;
                }
            }
        }
        solve(rStart,cStart,rEnd,cEnd,vis,grid);
        return count;
    }
};