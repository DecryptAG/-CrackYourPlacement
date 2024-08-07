// https://leetcode.com/problems/furthest-building-you-can-reach/description/

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int sum = 0;
        for(int i=0;i<n-1;i++)
        {
            if(pq.size()<ladders && (heights[i+1] - heights[i] > 0))
            {
                pq.push({heights[i+1] - heights[i],i});
            }
            else if(pq.size() == ladders && (heights[i+1] - heights[i] > 0))
            {   
                pq.push({heights[i+1] - heights[i],i});
                int h = pq.top().first;
                int ind = pq.top().second;
                pq.pop();
                sum+=h;
                if(sum > bricks)
                {
                    return i;
                }
            }
        }
        return n-1;
    }
};