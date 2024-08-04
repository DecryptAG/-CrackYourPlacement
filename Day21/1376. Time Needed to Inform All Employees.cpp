// https://leetcode.com/problems/time-needed-to-inform-all-employees/description/

class Solution {
public:
    int dfs(int node,vector<int> adj[],vector<int> &informTime, int headID,vector<int> &dp)
    {   
        if(adj[node].size()==0) return informTime[node];
        if(dp[node]!=-1)
            return dp[node];
        int maxi = INT_MIN;
        for(auto it:adj[node])
        {
            maxi = max(maxi,dfs(it,adj,informTime,headID,dp));
        }
        return dp[node] = informTime[node] + maxi;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        vector<int> dp(n+1,-1);
        for(int i=0;i<manager.size();i++)
        {
            if(manager[i]!=-1)
            {
                adj[manager[i]].push_back(i);
            }
        }
        return dfs(headID,adj,informTime,headID,dp);
    }
};