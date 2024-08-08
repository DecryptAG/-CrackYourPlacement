// https://www.geeksforgeeks.org/problems/min-coin5549/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int n;
	int solve(int ind,int amount,vector<int> &nums,vector<vector<int>> &dp)
	{   
	    
	    if(amount==0)
	        return 0;
	    if(ind == n-1)
	    {   
	        if(amount%nums[n-1] == 0)
	            return amount/nums[n-1];
	        return 1e9;
	    }
	    if(dp[ind][amount] !=-1)
	        return dp[ind][amount];
	    int pick = 1e9,notpick = 1e9;
	    if(nums[ind]<=amount)
	    {
	        pick = 1 + solve(ind,amount-nums[ind],nums,dp);
	    }
	    notpick = solve(ind+1,amount,nums,dp);
	    return dp[ind][amount] = min(pick,notpick);
	        
	    
	}
	int MinCoin(vector<int>nums, int amount)
	{   
	    n = nums.size();
	    sort(nums.begin(),nums.end(),greater<int>());
	    vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
	    int ans = solve(0,amount,nums,dp);
	   // cout<<ans<<endl;
	    if(ans >= 1e9)
	        return -1;
	    return ans;
	    // Code here
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends