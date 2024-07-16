// https://leetcode.com/problems/redundant-connection/description/

class Dsu{
    public:
    vector<int> parent,size;
    int components;
    Dsu(int n)
    {
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)
        {
            parent[i] = i;
        }
        components = n;
    }
    int findUparent(int node)
    {
        if(node==parent[node])
            return node;
        return parent[node] = findUparent(parent[node]);
    }
    void unionBySize(int n1,int n2)
    {
        int p1 = findUparent(n1);
        int p2 = findUparent(n2);
        if(p1==p2)
            return;
        if(size[p1]>size[p2])
        {
            parent[p2] = p1;
            size[p1]+=size[p2];
        }
        else
        {
            parent[p1] = p2;
            size[p2]+=size[p1];
        }
        components--;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> possible;
        int n = edges.size();
        Dsu ds(n);
        int prev_comp = ds.components;
        for(int i = 0;i<n;i++)
        {
            int x = edges[i][0];
            int y = edges[i][1];
            if(ds.findUparent(x)!=ds.findUparent(y))
            {
                ds.unionBySize(x,y);
            }
            else
            {
                possible.push_back(edges[i]);
            }
        }
        return possible.back();
    }
};