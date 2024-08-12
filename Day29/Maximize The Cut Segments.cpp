// https://www.geeksforgeeks.org/problems/cutted-segments1642/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int solve(int n,int x,int y,int z,vector<int> &dp)
    {
        if(n==0)
        {
            return 0;
        }
        if(dp[n]!=-1)
            return dp[n];
        int xcut = INT_MIN, ycut = INT_MIN, zcut = INT_MIN;
        if(n>=x)
        {
            xcut = 1 + solve(n-x,x,y,z,dp);
        }
        if(n>=y)
        {
            ycut = 1 + solve(n-y,x,y,z,dp);
        }
        if(n>=z)
        {
            zcut = 1 + solve(n-z,x,y,z,dp);
        }
        return dp[n] = max(xcut,max(ycut,zcut));
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {       
        vector<int> dp(n+1,-1);
        int a = solve(n,x,y,z,dp);
        if(a<0)
            return 0;
        return a;
        //Your code here
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends