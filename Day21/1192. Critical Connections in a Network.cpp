// https://leetcode.com/problems/critical-connections-in-a-network/description/

class Solution {
public:
    int timer =1;
    void dfs(int node,int parent,vector<int> adj[], vector<int> &time,vector<int> &lowestTime,vector<vector<int>> &bridges,vector<int> &vis)
    {
        vis[node] = 1;
        time[node] = lowestTime[node] = timer;
        timer++;
        for(auto it: adj[node])
        {
            if(it==parent)
            {
                continue;
            }
            else if(vis[it]==0)
            {
                dfs(it,node,adj,time,lowestTime,bridges,vis);
                lowestTime[node] = min(lowestTime[node],lowestTime[it]);
                if(lowestTime[it] > time[node])
                {
                    bridges.push_back({it,node});
                }
            }
            else
            {
                lowestTime[node] = min(lowestTime[node],lowestTime[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> time(n,0);
        vector<int> lowestTime(n,0);
        vector<vector<int>> bridges;
        vector<int> vis(n,0);
        dfs(0,-1,adj,time,lowestTime,bridges,vis);
        return bridges;
    }
};