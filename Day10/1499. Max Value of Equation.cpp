// https://leetcode.com/problems/max-value-of-equation/description/

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        pq.push({points[0][1] - points[0][0], points[0][0]});
        int ans = INT_MIN;
        for(int i =1;i<points.size();i++)
        {
            int x = points[i][0] + points[i][1];
            while(pq.size()>0 && points[i][0] - pq.top().second>k)
            {
                pq.pop();
            }
            if(pq.size()>0)
            {
                ans = max(ans, pq.top().first + x);
            }
            pq.push({points[i][1] - points[i][0], points[i][0]});
        }
        return ans;
    }
};