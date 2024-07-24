// https://leetcode.com/problems/merge-sorted-array/description/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0)
            return;
        int i = m-1;
        int j = n-1;
        int ind = n+m-1;
        while(j>=0 && i>=0)
        {   
                if(nums1[i]<=nums2[j])
                {
                    nums1[ind] = nums2[j];
                    ind--;
                    j--;
                }
                else if(nums1[i]>nums2[j])
                {
                    nums1[ind] = nums1[i];
                    i--;
                    ind--;
                }
        }
        while(j>=0)
        {
            nums1[ind] = nums2[j];
            j--;
            ind--;
        }
    }
};
