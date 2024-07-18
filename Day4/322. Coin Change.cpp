// https://leetcode.com/problems/coin-change/

class Solution {
public:
    int solve(int ind,vector<int> &coins, int amount, vector<vector<int>> &dp)
    {   
        if(amount ==0)
            return 0;
        if(ind==0)
        {
            if(coins[0]<=amount && amount%coins[0]==0)
            {
                return amount/coins[0];
            }
            else
            {
                return INT_MAX;
            }
        }
        if(dp[ind][amount]!=-1)
            return dp[ind][amount];
        int notpick = solve(ind-1,coins,amount,dp);
        int pick = 1e9;
        if(coins[ind]<=amount)
            pick = 1 + solve(ind,coins,amount-coins[ind],dp);
        return dp[ind][amount] = min(pick,notpick);

    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        if(amount == 0)
            return 0;
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        for(int i = 0;i<n;i++)
        {
            dp[i][0] = 0;
        }
        for(int i=1;i<amount+1;i++)
        {
            if(coins[0]<=i && i%coins[0]==0)
            {
                dp[0][i] = i/coins[0];
            }
            else
            {
                dp[0][i] = INT_MAX;
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j =1;j<=amount;j++)
            {
                int notpick = dp[i-1][j];
                int pick = 1e9;
                if(coins[i]<=j)
                    pick = 1 + dp[i][j-coins[i]];
                dp[i][j] = min(pick,notpick);
            }
        }
        if( dp[n-1][amount]>=1e9)
            return -1;
        return dp[n-1][amount];
        // int ans = solve(n-1,coins,amount,dp);
        // if(ans>=1e9)
        //     return -1;
        // return ans;
    }
};