// https://leetcode.com/problems/trapping-rain-water/description/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int mxl[n];
        int mxr[n];
        int water[n];
        mxl[0] = height[0];
        for(int i=1;i<n;i++)
        {
            mxl[i] = max(mxl[i-1],height[i]);
        }
        mxr[n-1]= height[n-1];
        for(int i = n-2;i>=0;i--)
        {
            mxr[i] = max(mxr[i+1],height[i]);
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            water[i] = min(mxr[i],mxl[i]) - height[i];
            sum = sum + water[i];
        }
        return sum;
    }
};