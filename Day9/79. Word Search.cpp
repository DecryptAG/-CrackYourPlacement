// https://leetcode.com/problems/word-search/

class Solution {
public:
    bool traversal(vector<vector<char>> &board, string word,int i, int j, int ind, vector<vector<int>> &vis)
    {   
        if(ind >= word.length())
            return true;
        vis[i][j] = 1;
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,-1,0,+1};
        int n = board.size();
        int m = board[0].size();
        for(int k=0;k<4;k++)
        {
            int r = i+drow[k];
            int c = j+dcol[k];
            if(r<n && r>=0 && c<m && c>=0 && vis[r][c]==0 && board[r][c]==word[ind])
            {   
                    if(traversal(board,word,r,c,ind+1,vis)==true)
                        return true;             
            }
        }
        vis[i][j] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(board[i][j] == word[0])
                {
                    if(traversal(board,word,i,j,1,vis))
                        return true;
                }
            }
        }
        return false;
    }
};