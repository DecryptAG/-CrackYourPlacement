// https://leetcode.com/problems/longest-increasing-subsequence/description/

class Solution {
public:
    int solve(int ind, int prev, vector<int> &nums, vector<vector<int>> &dp)
    {
        if(ind==nums.size())
            return 0;
        if(dp[ind][prev]!=-1)
            return dp[ind][prev];
        int pick = 0;
        int notpick = solve(ind+1,prev,nums,dp);
        if(prev==0 || nums[prev-1]<nums[ind])
        {   
            pick = 1 + solve(ind+1,ind+1,nums,dp);
        }
        
        return dp[ind][prev] = max(pick,notpick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,0,nums,dp);
        // vector<int> dp(n,1);
        // for(int i=0;i<n;i++)
        // {
        //     for(int prev = 0;prev<i;prev++)
        //     {
        //         if(nums[prev]<nums[i] && 1+dp[prev]>dp[i])
        //         {
        //             dp[i] = 1 + dp[prev];
        //         }
        //     }
        // }
        // return *max_element(dp.begin(),dp.end());
    }
};