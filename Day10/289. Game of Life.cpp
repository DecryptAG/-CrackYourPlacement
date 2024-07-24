// https://leetcode.com/problems/game-of-life/description/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {   
                int live = 0;
                int drow[] = {+1,0,0,-1,-1,-1,+1,+1};
                int dcol[] = {0,-1,+1,0,-1,+1,+1,-1};
                for(int k =0 ;k<8;k++)
                {
                    int r = i + drow[k];
                    int c = j + dcol[k];
                    if(r>=0 && r<n && c>=0 && c<m && (board[r][c] == 1 || board[r][c] == -1))
                    {
                        live++;
                    }
                }
                if(board[i][j] == 1)
                {
                    if(live<2)
                        board[i][j] = -1;
                    else if(live>3)
                        board[i][j] = -1;
                }
                else
                {
                    if(live == 3)
                        board[i][j] = 10;
                }
            }
        }
        for(int i = 0 ;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(board[i][j] == -1)
                    board[i][j] = 0;
                else if( board[i][j] == 10)
                    board[i][j] = 1;
            }
        }
    }
};