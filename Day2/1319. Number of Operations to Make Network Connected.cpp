// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

class Dsu{
    vector<int> parent,size;
    public:
    Dsu(int n)
    {
        parent.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)
        {
            parent[i] = i;
        }
    }
    int findUParent(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }
    void unionBySize(int n1, int n2)
    {   
        int p1 = findUParent(n1);
        int p2 = findUParent(n2);
        if(p1==p2)
        {
            return;
        }
        if(size[p1]<size[p2])
        {
            parent[p1] = p2;
            size[p2]+=size[p1];
        }
        else
        {
            parent[p2] = p1;
            size[p1]+=size[p2];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& con) {
        int m = con.size();
        if(!(m>=n-1))
            return -1;
        Dsu ds(n);
        for(int i=0;i<m;i++)
        {   
            if(ds.findUParent(con[i][0])!=ds.findUParent(con[i][1]))
                ds.unionBySize(con[i][0],con[i][1]);
        }
        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(ds.findUParent(i)==i)
            {
                count++;
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<ds.findUParent(i)<<" ";
        // }
        return max(0,count-1);
        
    }
};