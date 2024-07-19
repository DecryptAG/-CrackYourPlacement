// https://leetcode.com/problems/two-sum/description/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int start = 0, end = n-1; 
        while(start<end)
        {
            if(nums[start] + nums[end] > target)
            {
                end--;
            }
            else if(nums[start] + nums[end] < target)
            {
                start++;
            }
            else
            {
                return {start,end};
            }
        }
        return {-1,-1};
    }
};