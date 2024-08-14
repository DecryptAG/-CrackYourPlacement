// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

class Solution {
public:
    int solve(int i, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if(i== prices.size())
            return 0;
        if(cap==0)
            return 0;
        int profit = INT_MIN;
        if(dp[i][buy][cap]!=-1)
            return dp[i][buy][cap];
        if(buy)
        {
            profit = max(-prices[i]+solve(i+1,0,cap,prices,dp), 0 + solve(i+1,1,cap,prices,dp));
        }
        else
        {
            profit = max(prices[i]+solve(i+1,1,cap-1,prices,dp), 0 + solve(i+1,0,cap,prices,dp));
        }
        return  dp[i][buy][cap] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1,-1)));
        return solve(0,1,k,prices,dp);
    }
};