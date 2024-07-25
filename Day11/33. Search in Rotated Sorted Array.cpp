// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int next, prev;
        int index = 0;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            next = (mid+1)%n;
            prev= (mid+n-1)%n;
            if(nums[mid]<=nums[next] && nums[mid]<=nums[prev])
            {
                index = mid;
                break;
            }
            else if(nums[low]<=nums[mid])
            {
                low = mid+1;
            }
            else if(nums[mid]<=nums[high])
            {
                high = mid-1;
            }
        }
        int ans = -1;
            low = 0;
            high = index-1;
            while(low<=high)
            {
                int mid = low + (high-low)/2;
                if(nums[mid] == target)
                    {
                        ans = mid;
                        break;
                    }
                else if(target<nums[mid])
                {
                    high = mid-1;
                }
                else
                {
                    low = mid+1;
                }
            }
        if(ans == -1)
        {
            low = index;
            high = n-1;
            while(low<=high)
            {
                int mid = low + (high-low)/2;
                if(nums[mid] == target)
                {
                    ans = mid;
                    break;
                }
                else if(target<nums[mid])
                {
                    high = mid-1;
                }
                else
                {
                    low = mid+1;
                }
            }
        }
    return ans;
    }
};