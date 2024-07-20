// https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0]++;
        vector<int> pre(n,0);
        pre[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            pre[i] = pre[i-1] + nums[i];
        }
        for(int i=0;i<n;i++)
        {
            pre[i] = pre[i]%k;
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            pre[i] = (pre[i] + k)%k;
            ans+=mp[pre[i]];
            mp[pre[i]]++;
        }
        return ans;
    }
};