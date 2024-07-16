// https://leetcode.com/problems/flood-fill/description/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int c = image[sr][sc];
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int> (m,0));
        vis[sr][sc] = 1;
        q.push({sr,sc});
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            image[x][y] = color;
            q.pop();
            int drow[] = {+1,0,0,-1};
            int dcol[] = {0,-1,+1,0};
            for(int i=0;i<4;i++)
            {
                int row = x + drow[i];
                int col = y + dcol[i];
                if(row>=0 && row<n && col>=0 && col<m && !vis[row][col] && image[row][col] == c)
                {   
                    vis[row][col] = 1;
                    q.push({row,col});
                }
            }
        }
        return image;

    }
};