// https://leetcode.com/problems/combination-sum-ii/description/

class Solution {
public:
    int n;
    void solve(int ind, vector<int> &nums,int target, vector<vector<int>> &ans,vector<int> ds)
    {
        if(target == 0)
        {
            ans.push_back(ds);
            return;
        }
        if(ind>=n && target!=0)
            return;
        for(int i=ind;i<n;i++)
        {
            if(i>ind && nums[i]==nums[i-1]) continue;
            if(nums[i]>target)
                break;
            ds.push_back(nums[i]);
            solve(i+1,nums,target-nums[i],ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        n = nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0,nums,target,ans,ds);
        return ans;
    }
};