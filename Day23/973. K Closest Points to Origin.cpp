// https://leetcode.com/problems/k-closest-points-to-origin/description/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<points.size();i++)
        {   
            int x = points[i][0];
            int y = points[i][1];
            int dis = x*x + y*y;
            if(pq.size()<k)
                pq.push({dis,{x,y}});
            else if(dis<pq.top().first)
            {
                pq.pop();
                pq.push({dis,{x,y}});
            }
        }
        vector<vector<int>> ans;
        while(pq.size()>0)
        {
            vector<int> temp;
            temp.push_back(pq.top().second.first);
            temp.push_back(pq.top().second.second); 
            ans.push_back(temp);
            pq.pop();
        }
        return ans;
    }
};