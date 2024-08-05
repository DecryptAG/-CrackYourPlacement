// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {   
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<int> vis(V,0);
        int ans = 0;
        while(!pq.empty())
        {
            int node = pq.top().second;
            int w = pq.top().first;
            pq.pop();
            if(vis[node]==1)
                continue;
            vis[node] = 1;
            ans += w;
            for(auto it: adj[node])
            {
                int adjNode = it[0];
                int edgW = it[1];
                if(!vis[adjNode])
                {
                    pq.push({edgW,adjNode});
                }
            }
        }
        return ans;
        // code here
    }
};