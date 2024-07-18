// https://leetcode.com/problems/as-far-from-land-as-possible/description/

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dis(n,vector<int>(m,1e9));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    dis[i][j] = 0;
                    q.push({{i,j},0});
                }
            }
        }
        int maxi = -1;
        while(!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int d = q.front().second;
            q.pop();
            int drow[] = {+1,0,0,-1};
            int dcol[] = {0,-1,+1,0};
            for(int i=0;i<4;i++)
            {
                int r = x + drow[i];
                int c = y + dcol[i];
                if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==0 && dis[r][c]>d+1)
                {
                    dis[r][c] = d+1;
                    maxi = max(maxi,d+1);
                    q.push({{r,c},d+1});
                }
            }
        }
        return maxi;
    }
};