// https://leetcode.com/problems/range-sum-query-2d-immutable/description/

class NumMatrix {
public:
    vector<vector<int>> mat;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        mat.resize(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                mat[i][j] = matrix[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j = 1;j<m;j++)
            {
                mat[i][j] = mat[i][j] + mat[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for(int i = row1;i<=row2;i++)
        {      
            if(col1>0)
                ans+= mat[i][col2] - mat[i][col1-1];
            else
                ans+= mat[i][col2];
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */