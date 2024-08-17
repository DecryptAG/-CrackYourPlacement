// https://leetcode.com/problems/minimum-cost-to-merge-stones/description/

class Solution {
public:
    int solve(vector<int> &stones,int i,int j,int k,vector<vector<int>> &dp)
    {
        if(i>=j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans = INT_MAX;
        for(int ind = i;ind<j;ind+=k-1) // <---- Loop change operation -- tough
        {   
            int cost = solve(stones,i,ind,k,dp) + solve(stones,ind+1,j,k,dp);
            ans = min(ans,cost);
        }
        if((j-i)%(k-1)==0)
        {
            int sum = 0;
            for(int ind = i;ind<=j;ind++)
            {
                sum += stones[ind];
            }
            ans+=sum;
        }
        return dp[i][j] = ans;
    }
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if((n-1)%(k-1)!=0)
            return -1;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(stones,0,n-1,k,dp);

    }
};