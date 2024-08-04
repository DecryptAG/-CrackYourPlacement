// https://leetcode.com/problems/making-a-large-island/description/

class Dsu{
    public:
    vector<int> parent, size;
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        Dsu ds(n*n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                    int drow[] = {-1,0,0,+1};
                    int dcol[] = {0,-1,+1,0};
                    for(int k=0;k<4;k++)
                    {   
                        int r = i + drow[k];
                        int c = j + dcol[k];
                        if(r<n && r>=0 && c>=0 && c<n && grid[r][c]==1)
                        {
                            if(ds.findUParent(i*n+j)==ds.findUParent(r*n+c))
                            {
                                continue;
                            }
                            elses
                            {
                                ds.unionBySize(i*n+j,r*n+c);
                            }
                        }
                    }
                }
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {   
                set<int> component;
                if(grid[i][j]==0)
                {
                    int drow[] = {-1,0,0,+1};
                    int dcol[] = {0,-1,+1,0};
                    for(int k=0;k<4;k++)
                    {   
                        int r = i + drow[k];
                        int c = j + dcol[k];
                        if(r<n && r>=0 && c>=0 && c<n && grid[r][c]==1)
                        {
                            component.insert(ds.findUParent(r*n+c));
                        }
                    }
                }
                int c=0;
                for(auto it: component)
                {   
                    c+=ds.size[it];
                    
                }
                ans = max(ans,c+1);
            }
        }
        for(int i=0;i<n*n;i++)
        {
           ans = max(ans,ds.size[ds.findUParent(i)]);
        }
        return ans;
    }
};