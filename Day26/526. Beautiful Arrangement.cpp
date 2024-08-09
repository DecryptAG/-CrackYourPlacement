// https://leetcode.com/problems/beautiful-arrangement/solutions/3627908/c-solution-bitmask-dp-memoization/

class Solution {
public:
    void solve(int ind, vector<int> &nums, int &count, vector<int> &vis, int n)
    {
        if(ind== n+1)
        {
            count++;
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i] && (nums[ind]%i==0 || i%nums[ind]==0))
            {
                vis[i] =1;
                solve(ind+1,nums,count,vis,n);
                vis[i] = 0;
            }
        }
    } 
    int countArrangement(int n) {
        vector<int> nums(n+1);
        for(int i=1;i<=n;i++)
            nums[i] = i;
        int count = 0;
        vector<int> vis(n+1,0);
        solve(1,nums,count,vis,n);
        return count;
    }
};