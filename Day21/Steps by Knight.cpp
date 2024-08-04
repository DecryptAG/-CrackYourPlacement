// https://www.geeksforgeeks.org/problems/steps-by-knight5927/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{   
	    int x = KnightPos[0]-1;
	    int y = KnightPos[1]-1;
	    int x1 = TargetPos[0]-1;
	    int y1 = TargetPos[1]-1;
	    if(x==x1 && y == y1)
	        return 0;
	   
	    vector<vector<int>> grid(N,vector<int>(N,0));
	    queue<pair<pair<int,int>,int>> q;
	    q.push({{x,y},0});
	    grid[x][y] = 1;
	    while(!q.empty())
	    {
	        int i = q.front().first.first;
	        int j = q.front().first.second;;
	        int d = q.front().second;
	        q.pop();
	        if(i==x1 && j==y1)
	        {
	            return d;
	        }
	        int drow[] = {-2,-2,-1,-1,+1,+1,+2,+2};
	        int dcol[] = {+1,-1,+2,-2,+2,-2,-1,+1};
	        for(int k = 0;k<8;k++)
	        {
	            int r = i + drow[k];
	            int c = j + dcol[k];
	            if(r>=0 && r<N && c>=0 && c<N && grid[r][c]!=1)
	            {
	                grid[r][c] = 1;
	                q.push({{r,c},d+1});
	            }
	        }
	    }
	    return -1;
	    // Code here
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends