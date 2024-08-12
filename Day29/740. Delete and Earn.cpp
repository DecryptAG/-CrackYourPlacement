// https://leetcode.com/problems/delete-and-earn/description/

class Solution {
public:
    int solve(int ind, vector<int> &temp,unordered_map<int,int> &mp,vector<int> &dp)
    {
        if(ind<0)
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int notpick = solve(ind-1,temp,mp,dp);
        int pick = INT_MIN;
        if(ind>0 && temp[ind-1]==temp[ind]-1)
            pick = temp[ind]*mp[temp[ind]] + solve(ind-2,temp,mp,dp);
        else
            pick = temp[ind]*mp[temp[ind]] + solve(ind-1,temp,mp,dp);
        return dp[ind] = max(pick,notpick);
    }
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        vector<int> temp;
        for(auto it: mp)
        {
            temp.push_back(it.first);
        }
        int x = temp.size();
        sort(temp.begin(),temp.end());
        vector<int> dp(x+1,-1);
        return solve(x-1,temp,mp,dp);
    }
};