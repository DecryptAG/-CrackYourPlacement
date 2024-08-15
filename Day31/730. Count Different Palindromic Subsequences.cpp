// https://leetcode.com/problems/count-different-palindromic-subsequences/description/

const int M = 1e9+7;
class Solution {
public:
    int solve(string &s, int i, int j,vector<vector<int>> &dp)
    {
        if(i==j)
            return 1;
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int num = 0;
        if(s[i] != s[j])
        {   
            
            int a = solve(s,i+1,j,dp)%M;
            int b = solve(s,i,j-1,dp)%M;
            int c = solve(s,i+1,j-1,dp)%M;
            num = a+b-c;
        }
        else
        {   
            num =( 2 * (solve(s,i+1,j-1,dp)%M))%M;
            int left = i+1, right = j-1;
            while( left<=right && s[left]!=s[i] ) left++;
            while( left<=right && s[right]!=s[j] ) right--;

            if(left<right) 
                num = (num - solve(s,left+1,right-1,dp)%M)%M;
            else if(left==right) 
                num = (num + 1)%M;
            else num = (num + 2)%M;
        }
        return dp[i][j] = num<0? num+1000000007:num%1000000007;
    }
    int countPalindromicSubsequences(string s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(s,0,s.length()-1,dp);
    }
};