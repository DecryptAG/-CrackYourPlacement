// https://leetcode.com/problems/sum-of-distances-in-tree/description/

class Solution {
public:
    int ans_zero = 0;
    int N;
    int dfs(int node,unordered_map<int,vector<int>> &adj,vector<int> &count,int dist,int parent)
    {   
        int childrenCount = 1;
        ans_zero+=dist;
        for(auto it: adj[node])
        {   
            if(it!=parent)
            {   
                childrenCount+=dfs(it,adj,count,dist+1,node);
            }
        }
        count[node] = childrenCount;
        return childrenCount;
    }
    void dfsCheck(int node,unordered_map<int,vector<int>> &adj,vector<int> &count,vector<int> &ans,int parent)
    {
        for(auto it: adj[node])
        {
            if(it!=parent)
            {
                ans[it] = ans[node] + (N - count[it]) - count[it];
                dfsCheck(it,adj,count,ans,node);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> count(n,0);
        vector<int> ans(n,0);
        dfs(0,adj,count,0,-1);
        ans[0] = ans_zero;
        dfsCheck(0,adj,count,ans,-1);
        return ans;
    }
};