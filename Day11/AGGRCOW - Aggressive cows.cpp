// https://www.spoj.com/problems/AGGRCOW/

#include <iostream>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
#include <set>
#include <vector>
#include <cstdlib>
#include<bits/stdc++.h>
#include <stdio.h>
using namespace std;
 
#define pb push_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int long long
typedef long long ll;
 
// ****** S E I V E ************
// 
// vector<bool> isPrime(1e6,true);
//     isPrime[0] = isPrime[1] = false;
//     for(ll i=2;i<1e6;i++)
//     {   
//         if(isPrime[i])
//         {
//             for(ll j =2*i;j<1e6;j+=i)
//             {
//                 isPrime[j] = false;
//             }
//         }
//     }

// class Dsu{
//     public:
//     vector<int> parent,size;
//     Dsu(int n)
//     {
//         parent.resize(n+1,0);
//         size.resize(n+1,1);
//         for(int i=0;i<=n;i++)
//         {
//             parent[i] = i;
//         }
//     }
//     int findUParent(int node)
//     {
//         if(node==parent[node])
//         {
//             return node;
//         }
//         return parent[node] = findUParent(parent[node]);
//     }
//     void unionBySize(int n1, int n2)
//     {   
//         int p1 = findUParent(n1);
//         int p2 = findUParent(n2);
//         if(p1==p2)
//         {
//             return;
//         }
//         if(size[p1]<size[p2])
//         {
//             parent[p1] = p2;
//             size[p2]+=size[p1];
//         }
//         else
//         {
//             parent[p2] = p1;
//             size[p1]+=size[p2];
//         }
//     }
// };
// void dfsCheck(int node, vector<int> adj[],vector<int> &visited, int &count)
// {
//     visited[node] = 1;
//     for(auto it: adj[node])
//     {
//         if(!visited[it])
//         {   
//             count++;
//             dfsCheck(it,adj,visited,count);
//         }
//     }
// }

int check(vector<int> &nums, int mid)
{   
    int c = 1;
    int s = nums[0];
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>=s+mid)
        {
            c++;
            s = nums[i];
        }
    }
    return c;
}

int solve(int ind,vector<pair<int,int>> &vec, int b)
{
    if(ind<0)
        return 0;
    int pick = vec[ind].first + solve(ind-1,vec,b+vec[ind].second);
    int notpick = vec[ind].second + solve(ind-1,vec,b+vec[ind].first);
    return b;
    return min(max(pick,notpick),b);
}
signed main(){
     ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);   
    int t;
    cin>>t;
    while(t--)
    {   
        int n,c;
        cin>>n>>c;
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        sort(all(v));
        int low = 1;
        int high = *max_element(all(v));
        int ans = 0;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int k = check(v,mid);
            // cout<<mid<<" "<<k<<endl;
            if(k>=c)
            {
                ans = mid;
                low = mid+1;
            }
            else
                high = mid-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
