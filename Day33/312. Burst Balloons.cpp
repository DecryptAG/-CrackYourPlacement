// https://leetcode.com/problems/burst-balloons/description/

class Solution {
public:
    int solve(vector<int> &nums,int i, int j,vector<vector<int>> &dp)
    {
        if(i>j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int kost = INT_MIN;
        for(int k = i;k<=j;k++)
        {
            int cost = nums[i-1]*nums[k]*nums[j+1] + solve(nums,i,k-1,dp) + solve(nums,k+1,j,dp);
            kost = max(cost,kost);
            
        }
        return dp[i][j] = kost;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin()+0,1);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(nums,1,n,dp);
    }
};