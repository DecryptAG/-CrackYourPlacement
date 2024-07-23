// https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            int ind = abs(nums[i]) - 1;
            if(nums[ind]<0)
                ans.push_back(ind+1);
            else
                nums[ind] = -nums[ind];
        }
        return ans;
    }
};
