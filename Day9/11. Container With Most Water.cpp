// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int ans = INT_MIN;
        while(i<j)
        {
            int width = j-i;
            ans = max(ans,width*min(height[i],height[j])) ;
            if(height[i]<height[j])
            {
                i++;
            }
            else if(height[j]<height[i])
            {
                j--;
            }
            else
            {
                i++;
                j--;
            }
        }
        return ans;
    }
};