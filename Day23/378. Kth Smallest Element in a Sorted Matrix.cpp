// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int n = matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(pq.size()<k)
                {
                    pq.push(matrix[i][j]);
                }
                else
                {
                    int x = pq.top();
                    pq.pop();
                    pq.push(min(x,matrix[i][j]));
                }
            }
        }
        return pq.top();
    }
};