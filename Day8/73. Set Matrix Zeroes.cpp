// https://leetcode.com/problems/set-matrix-zeroes/description/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int extra = 1;
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {   
                if(matrix[i][j]==0)
                {
                    matrix[0][j] = 0;
                    if(i>0)
                        matrix[i][0] = 0;
                    else
                        extra = 0;
                }
            }
        }
        for(int i=1;i<m;i++)
        {
            if(matrix[0][i] == 0)
            {
                for(int j = 0;j<n;j++)
                {   
                    matrix[j][i] = 0;
                }
            }
        }
        for(int j = 1;j<n;j++)
        {
            if(matrix[j][0] == 0)
            {
                for(int i=0;i<m;i++)
                {   
                    matrix[j][i] = 0;
                }
            }
        }
        if(matrix[0][0] == 0)
        {
            for(int i=0;i<n;i++)
            {
                matrix[i][0] = 0;
            }
        }
        if(extra == 0)
        {
            for(int i = 0; i<m;i++)
            {
                matrix[0][i] = 0;
            }
        }
    }
};