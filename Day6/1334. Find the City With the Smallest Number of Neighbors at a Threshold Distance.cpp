// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/


class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n,vector<int>(n,1e9));
        for(int i=0;i<edges.size();i++)
        {
            matrix[edges[i][0]][edges[i][1]] = edges[i][2];
            matrix[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for(int i=0;i<n;i++)
        {
            matrix[i][i] = 0;
        }
        for(int k = 0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j =0;j<n;j++)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
        int ansCity = -1;
        int mini = INT_MAX;
        for(int i=0;i<n;i++)
        {   
            int c = 0;
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]<=distanceThreshold)
                {
                    c++;
                }
            }
            // cout<<c<<endl;
            if(mini>=c)
            {
                mini = min(c,mini);
                ansCity = i;
            }
        }
        return ansCity;
    }
};