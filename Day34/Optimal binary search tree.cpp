// https://www.geeksforgeeks.org/problems/optimal-binary-search-tree2214/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int solve(int keys[],int freq[],int i,int j,vector<vector<int>> &dp)
    {   
        if(i>j)
            return 0;
        if(i==j)
            return freq[i];
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(j-i==1)
            {
                int f1 = freq[i];
                int f2 = freq[j];
                return dp[i][j] = min(f1+2*f2, f2+2*f1);
            }
        int ans = INT_MAX;
        for(int k=i;k<=j;k++)
        {
            int cost = solve(keys,freq,i,k-1,dp) + solve(keys,freq,k+1,j,dp);
            ans = min(ans,cost);
        }
        for(int k = i;k<=j;k++)
        {
            ans+=freq[k];
        }
        return dp[i][j] = ans;
        
    }
    int optimalSearchTree(int keys[], int freq[], int n)
    {       
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(keys,freq,0,n-1,dp);
        // code here
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends