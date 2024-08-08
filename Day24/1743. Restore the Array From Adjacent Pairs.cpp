// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/description/

class Solution {
public:
    vector<int> ans;
    void dfs(int node,unordered_map<int,vector<int>> &adj,int parent)
    {
        ans.push_back(node);
        for(auto it: adj[node])
        {
            if(it!=parent)
            {
                dfs(it,adj,node);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& nums) {
        int n= nums.size();
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<n;i++)
        {
            int x = nums[i][0];
            int y = nums[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(auto it: adj)
        {
            if(it.second.size() == 1)
            {
                dfs(it.first,adj,INT_MIN);
                break;
            }
        }
        return ans;
    }
};