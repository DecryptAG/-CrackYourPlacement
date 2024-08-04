// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/

class Dsu{
    public: 
    vector<int> parent,size;
    Dsu(int n)
    {
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)
        {
            parent[i] = i;
        }
    }
    int findUParent(int node)
    {
        if(node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }
    void unionBySize(int n1, int n2)
    {
        int p1 = findUParent(n1);
        int p2 = findUParent(n2);
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
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;
        for(int i=0;i<n;i++)
        {
            maxRow = max(stones[i][0],maxRow);
            maxCol = max(stones[i][1],maxCol);
        }
        Dsu ds(maxRow+maxCol+1);
        for(int i=0;i<n;i++)
        {
            ds.unionBySize(stones[i][0],stones[i][1]+maxRow+1);
        }
        int c = 0;
        for(int i=0;i<=maxRow+maxCol+1;i++)
        {   
            if(ds.findUParent(i)==i && ds.size[i]>1)
            {
                c++;
            }
        }
        return n-c;
    }
};