// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, cost = 0, mini = INT_MAX; 
        for(int i=0;i<prices.size();i++)
        {
            cost = prices[i]-mini;
            profit = max(profit, cost);
            mini = min(mini,prices[i]);
        }
        return profit;
    }
};