// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> smallerRight, smallerLeft;
        stack<pair<int,int>> st;
        int n = heights.size();
        for(int i = n-1;i>=0;i--)
        {
            if(st.size()==0)
            {
                smallerRight.push_back(-1);
            }
            else if(st.size()>0 && st.top().first < heights[i])
            {
                smallerRight.push_back(st.top().second);
            }
            else if(st.size()>0 && st.top().first >= heights[i])
            {
                while(st.size()>0 && st.top().first >= heights[i])
                {
                    st.pop();
                }
                if(st.size()==0)
                {
                    smallerRight.push_back(-1);
                }
                else
                {
                    smallerRight.push_back(st.top().second);
                }
            }
            st.push({heights[i],i});
        }
        for(int i=0;i<n;i++)
        {
            if(smallerRight[i] == -1)
                smallerRight[i] = n;
        }
        reverse(smallerRight.begin(),smallerRight.end());
        while(!st.empty())
            st.pop();
        for(int i = 0;i<n;i++)
        {
            if(st.size()==0)
            {
                smallerLeft.push_back(-1);
            }
            else if(st.size()>0 && st.top().first < heights[i])
            {
                smallerLeft.push_back(st.top().second);
            }
            else if(st.size()>0 && st.top().first >= heights[i])
            {
                while(st.size()>0 && st.top().first >= heights[i])
                {
                    st.pop();
                }
                if(st.size()==0)
                {
                    smallerLeft.push_back(-1);
                }
                else
                {
                    smallerLeft.push_back(st.top().second);
                }
            }
            st.push({heights[i],i});
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int h = heights[i];
            int w = smallerRight[i] - smallerLeft[i] - 1;
            ans = max(ans, h*w);
        }
        return ans;
    }
};