// https://leetcode.com/problems/permutations-ii/description/

class Solution {
public:
    void solve(int ind, set<vector<int>> &ans, vector<int> &nums)
    {
        if(ind==nums.size())
        {
            ans.insert(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++)
        {   
            swap(nums[i],nums[ind]);
            solve(ind+1,ans,nums);
            swap(nums[i],nums[ind]);         
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        vector<vector<int>> output;
        solve(0,ans,nums);
        for( auto it: ans)
        {
            output.push_back(it);
        }
        return output;
    }
};