// https://leetcode.com/problems/shortest-bridge/description/

class Solution {
public:
    int n;
    void dfs(int i,int j, vector<vector<int>> &grid, vector<vector<int>> &vis, queue<pair<int,int>> &q)
    {
        vis[i][j] = 1;
        q.push({i,j});
        int drow[] = {+1,0,0,-1};
        int dcol[] = {0,-1,+1,0};
        for(int k=0;k<4;k++)
        {
            int r = i + drow[k];
            int c = j + dcol[k];
            if(r<n && r>=0 && c<n && c>=0 && grid[r][c]==1 && vis[r][c]==0)
            {
                dfs(r,c,grid,vis,q);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        queue<pair<int,int>> q;
        int flag = 0;
        for(int i=0;i<n;i++)
        {   
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j] == 1)
                {   
                    dfs(i,j,grid,vis,q);
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
            
        }
        int level = 0;
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                int drow[] = {+1,0,0,-1};
                int dcol[] = {0,-1,+1,0};
                for(int k=0;k<4;k++)
                {
                    int row = r + drow[k];
                    int col = c + dcol[k];
                    if(row<n && row>=0 && col<n && col>=0 && grid[row][col]==1 && vis[row][col]==0)
                    {
                        return level;
                    }
                    else if(row<n && row>=0 && col<n && col>=0 && grid[row][col]==0 && vis[row][col]==0)
                    {   
                        vis[row][col] = 1;
                        q.push({row,col});
                    }
                }
            }
            level++;
        }
        return -1;
    }
};