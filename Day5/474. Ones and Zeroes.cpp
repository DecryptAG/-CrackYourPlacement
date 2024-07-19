// https://leetcode.com/problems/ones-and-zeroes/description/

class Solution {
public:
    int solve(int m,int n, vector<pair<string,pair<int,int>>> &vec, int ind,vector<vector<vector<int>>> &dp)
    {
        if(ind == vec.size())
            return 0;
        if(m==0 && n==0)
            return 0;
        if(dp[m][n][ind]!=-1)
            return dp[m][n][ind];
        string str = vec[ind].first;
        int zero = vec[ind].second.first;
        int one = vec[ind].second.second;
        int pick = 0;
        if(m>=zero && n>=one)
        {
            pick = 1 + solve(m-zero,n-one,vec,ind+1,dp);
        }
        int notpick = solve(m,n,vec,ind+1,dp);
        return dp[m][n][ind] = max(pick,notpick);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<pair<string,pair<int,int>>> vec;
        for(int i=0;i<size;i++)
        {
            int zero = 0, one = 0;
            for(int j = 0;j<strs[i].size();j++)
            {
                if(strs[i][j]=='0')
                    zero++;
                else
                    one++;
            }
            if(zero<=m && one<=n)
                vec.push_back({strs[i],{zero,one}});
        }
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(vec.size()+1,-1)));
        return solve(m,n,vec,0,dp);
    }
};
//Tc - O(n*m) + O(n)
//SC - O(n) + O(n*m*n) + O(n)