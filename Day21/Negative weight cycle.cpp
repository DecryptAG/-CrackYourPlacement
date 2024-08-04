// https://www.geeksforgeeks.org/problems/negative-weight-cycle3504/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int> dist(n,1e9);
	    dist[0] = 0;
	    for(int i=0;i<n-1;i++)
	    {
	        for(auto it:edges)
	        {
	            int x = it[0];
	            int y = it[1];
	            int d = it[2];
	            if(dist[y] > d + dist[x])
	            {
	                dist[y] = dist[x]+d;
	            }
	        }
	    }
	    for(auto it:edges)
	        {
	            int x = it[0];
	            int y = it[1];
	            int d = it[2];
	            if(dist[y] > d + dist[x])
	            {
	                return 1;
	            }
	        }
	   return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends