// https://leetcode.com/problems/find-eventual-safe-states/description/

class Solution {
public:
    bool dfs(int root, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis, vector<int> &ans)
    {
        vis[root] = 1;
        pathVis[root] = 1;
        for(auto it: adj[root])
        {
            if(!vis[it])
            {
                if(dfs(it,adj,vis,pathVis,ans)==true)
                    return true;
            }
            else if(pathVis[it])
            {
                return true;
            }
        }
        ans[root] =1;
        pathVis[root] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        vector<int> ans(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,graph,vis,pathVis,ans);
            }
        }
        vector<int> temp;
        for(int i=0;i<n;i++)
        {
            if(ans[i])
                temp.push_back(i);
        }
        return temp;
    }
};