// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<flights.size();i++)
        {
            int x = flights[i][0];
            int y = flights[i][1];
            int w = flights[i][2];
            adj[x].push_back({y,w});
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src] = 0;
        while(!pq.empty())
        {
            int node = pq.top().second.first;
            int w = pq.top().second.second;
            int count = pq.top().first; 
            pq.pop();
            if(count>k)
                continue;
            for(auto it: adj[node])
            {   
                int x = it.first;
                int wt = it.second;
                if(dist[x] > w + wt && count<=k) 
                {   
                    dist[x] = w + wt;
                    pq.push({count+1,{x,dist[x]}});
                }
            }
        }
        if(dist[dst]==1e9)
            return -1;
        return dist[dst];
    }
};