// https://leetcode.com/problems/subsets/description/

class Solution {
public:
    void solve(int i, vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans)
    {
        if(i==nums.size())
        {
            ans.push_back(ds);
            return;
        }
            ds.push_back(nums[i]);
            solve(i+1,ds,nums,ans);
            ds.pop_back();
            solve(i+1,ds,nums,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0,ds,nums,ans);
        return ans;
    }
};