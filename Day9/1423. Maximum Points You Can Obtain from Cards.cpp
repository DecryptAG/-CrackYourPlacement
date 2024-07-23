// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n,0);
        pre[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            pre[i] = pre[i-1] + nums[i];
        }
        int i = 0, j = 0;
        int sum = 0;
        int ans = INT_MIN;
        if(n-k ==0)
            return pre[n-1];
        while(i<n && j<n)
        {   
            if(j-i+1 < n-k)
            {
                j++;
                
                continue;
            }
            int windowSum = 0;
            if(i>0)
                windowSum = pre[j] - pre[i-1];
            else
                windowSum = pre[j];
            ans = max(ans,pre[n-1] - windowSum);
            i++;
            j++;
        }
        return ans;
    }
};