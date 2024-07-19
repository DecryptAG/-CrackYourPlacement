// https://leetcode.com/problems/swim-in-rising-water/description/


class Solution {
public:
    int n;
    bool check(vector<vector<int>> &dist, int mid)
    {
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0] = 1;
        if(dist[0][0]>mid)
            return false;
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if(r==n-1 && c==n-1)
            {
                return true;
            }
            int drow[] = {+1,0,0,-1};
            int dcol[] = {0,-1,+1,0};
            for(int j=0;j<4;j++)
                {
                    int row = r + drow[j];
                    int col = c + dcol[j];
                    if(row>=0 && row<n && col>=0 && col<n && vis[row][col]==0 && dist[row][col]<=mid)
                    {
                        vis[row][col] = 1;
                        q.push({row,col});
                    }
                }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int l = 0, h = 2500;
        int result = 0;
        while(l<=h)
        {
            int mid = l + (h-l)/2;
            if(check(grid,mid))
            {
                result = mid;
                h = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return result;
    }
};