// https://leetcode.com/problems/move-zeroes/description/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        while(i<n)
        {
            if(nums[i]!=0)
                i++;
            break;
        }
        while(j<n)
        {
            if(nums[j]==0)
                j++;
            break;
        }
        if(j==n || i==n)
        {
            return;
        }
        while(j<n)
        {
            swap(nums[i],nums[j]);
            while(i<n)
            {
                if(nums[i]!=0)
                    i++;
                break;
            }
            while(j<n)
            {
                if(nums[j]==0)
                    j++;
                break;
            }
        }
    }
};
