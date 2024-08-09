// https://leetcode.com/problems/sudoku-solver/description/

class Solution {
public:
    bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {
        for(int i=0;i<board.size();i++)
        {
            if(board[row][i]==c)
                return false;
            if(board[i][col] == c)
                return false;
            if(board[3*(row/3)+i/3][3*(col/3) + i%3] ==c)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char k='1';k<='9';k++)
                    {
                        if(isValid(board,i,j,k))
                        {
                            board[i][j] = k;
                            if(solve(board)) 
                                return true;
                            else 
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};