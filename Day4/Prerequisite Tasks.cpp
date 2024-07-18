// https://www.geeksforgeeks.org/problems/prerequisite-tasks/1


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int n,int P, vector<pair<int, int> >& pre) {
	    // Code here
	    vector<int> adj[n];
	    for(int i=0;i<pre.size();i++)
	    {
	        int x = pre[i].first;
	        int y = pre[i].second;
	        adj[y].push_back(x);
	    }
	    vector<int> indegree(n,0);
	    for(int i=0;i<n;i++)
	    {
	        for(auto it: adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<n;i++)
	    {
	        if(indegree[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    vector<int> topo;
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto it: adj[node])
	        {
	            indegree[it]--;
	            if(indegree[it]==0)
	            {
	                q.push(it);
	            }
	        }
	    }
	    if(topo.size()==n)
	        return true;
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends