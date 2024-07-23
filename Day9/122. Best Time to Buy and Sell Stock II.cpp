// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

class Solution {
public:
    int solve(int i, int buy, vector<int> &prices,vector<vector<int>> &dp)
    {   
        if(i==prices.size())
        {
            return 0;
        }   
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        int profit = INT_MIN;
        if(buy)
        {
            profit = max(-prices[i] + solve(i+1,0,prices,dp), 0+solve(i+1,1,prices,dp));
        }
        else
        {
            profit = max(prices[i] + solve(i+1,1,prices,dp), 0+solve(i+1,0,prices,dp));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        dp[n][0] = 0;
        dp[n][1] = 0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {   
                int profit = INT_MIN;
                if(j)
                {
                    profit = max(-prices[i] + dp[i+1][0], 0+dp[i+1][1]);
                }
                else
                {
                    profit = max(prices[i] + dp[i+1][1], 0+dp[i+1][0]);
                }
                dp[i][j] = profit;
            }
        }
        return dp[0][1];
    }
};