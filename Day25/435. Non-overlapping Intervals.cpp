// https://leetcode.com/problems/non-overlapping-intervals/description/

class compare{
public:
    bool operator()(vector<int> x,vector<int> y)
    {
        return x[1]<y[1];
    }   
};
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end(),compare());
        // for(auto it)
        int last = nums[0][1];
        int ans = 0;
        for(int i=1;i<n;i++)
        {
            if(nums[i][0]>=last)
            {
                last = nums[i][1];
                continue;
            }
            {
                ans++;
            }
        }
        return ans;
    }
};