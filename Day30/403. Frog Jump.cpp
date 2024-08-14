// https://leetcode.com/problems/frog-jump/description/

class Solution {
public:
    int n;
    bool solve(int ind,int k, vector<int> &stones,vector<vector<int>> &dp)
    {
        if(ind>=n-1)
            return true;
        if((stones[ind] + k + 1 < stones[ind+1]))
            return false;
        if(dp[ind][k]!=-1)
            return dp[ind][k];
        int minus = false, org = false, plus = false;
        for(int i = ind+1;i<n;i++)
        {
            if((stones[ind] + k-1) == stones[i])
            {   
                // cout<<ind<<"k-1"<<endl;
                minus = true && solve(i,k-1,stones,dp);
            }
        }
        
        for(int i = ind+1;i<n;i++)  
        {
            if((stones[ind] + k) == stones[i])
            {   
                // cout<<ind<<"k"<<endl;
                org = true && solve(i,k,stones,dp);
            }
        }
        
        for(int i = ind+1;i<n;i++)   
        {
            if((stones[ind] + k + 1) == stones[i])
            {   
                // cout<<ind<<"k+1"<<endl;
                plus = true && solve(i,k+1,stones,dp);
            }
        }
        return dp[ind][k] = minus || org || plus;
        
    }
    bool canCross(vector<int>& stones) {
        n = stones.size();
        if(stones[1]>1)
            return false;
        int maxi = 0;
        for(int i=1;i<n;i++)
        {
            maxi = max(maxi,stones[i] - stones[i-1]);
        }
        vector<vector<int>> dp(n,vector<int>(2000+1,-1));
        return solve(1,1,stones,dp);
    }
};