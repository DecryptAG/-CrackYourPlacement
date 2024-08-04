// https://leetcode.com/problems/evaluate-division/description/

class Solution {
public:
    void dfs(string root,unordered_map<string,int> &vis,unordered_map<string,vector<pair<string,double>>> &mp, string dest, double product, double &ans)
    {   
        vis[root]++;
        if(root == dest)
        {
            ans = product;
            return;
        }
        for(auto it: mp[root])
        {
            if(vis[it.first]==0)
            {
                dfs(it.first,vis,mp,dest,product*it.second,ans);
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string,double>>> mp;
        int n = values.size();
        for(int i=0;i<n;i++)
        {
            mp[equations[i][0]].push_back({equations[i][1],values[i]});
            mp[equations[i][1]].push_back({equations[i][0],1.0/values[i]});
        }
        vector<double> result;
        for(int i=0;i<queries.size();i++)
        {   
            double ans = -1.0;
            double product = 1.0;
            if(mp.find(queries[i][0])!=mp.end())
            {   
                unordered_map<string,int> vis;
                dfs(queries[i][0],vis,mp,queries[i][1],product,ans);
            }
            result.push_back(ans);
        }
        return result;
    }
};