// https://leetcode.com/problems/jump-game/description/

class Solution {
public:
    int n;
    bool solve(int ind, vector<int> &nums, vector<int> &dp)
    {
        if(ind >= n-1)
        {
            return true;
        }
        if(dp[ind]!=-1)
            return dp[ind];
        bool possible = false;
        for(int i = 1;i<=nums[ind];i++)
        {
            possible = true && solve(ind+i,nums,dp);
            if(possible==true)
                return dp[ind] = true;
        }
        return dp[ind] = possible;
    }
    bool canJump(vector<int>& nums) {
        n = nums.size();
        if(n==1)
            return true;
        vector<int> dp(n+1,-1);
        return solve(0,nums,dp);
    }
};