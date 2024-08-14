// https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int n,int sum,int arr[],vector<vector<int>> &dp)
    {
        if(sum==0)
            return 1;
        if(n<0 && sum!=0)
            return 0;
        if(dp[n][sum]!=-1)
            return dp[n][sum];
        int pick = 0;
        if(arr[n]<=sum)
        {
            pick = solve(n-1,sum-arr[n],arr,dp);
        }
        int notpick = solve(n-1,sum,arr,dp);
        return dp[n][sum] = pick or notpick;
    }
    int equalPartition(int n, int arr[])
    {   
        int tot = accumulate(arr,arr+n,0);
        if(tot%2!=0)
            return 0;
        int sum = tot/2;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return solve(n-1,sum,arr,dp);
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends