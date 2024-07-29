// https://leetcode.com/problems/sum-of-subarray-minimums/description/

const int M = 1e9+7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> smallerRight, smallerLeft;
        stack<pair<int,int>> st;
        for(int i = n-1;i>=0;i--)
        {
            if(st.size()==0)
            {
                smallerRight.push_back(-1);
            }
            else if(st.size()>0 && st.top().first < arr[i])
            {
                smallerRight.push_back(st.top().second);
            }
            else if(st.size()>0 && st.top().first >= arr[i])
            {
                while(st.size()>0 && st.top().first >= arr[i])
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
            st.push({arr[i],i});
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
            else if(st.size()>0 && st.top().first <= arr[i])
            {
                smallerLeft.push_back(st.top().second);
            }
            else if(st.size()>0 && st.top().first > arr[i])
            {
                while(st.size()>0 && st.top().first > arr[i])
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
            st.push({arr[i],i});
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int left = i - smallerLeft[i];
            int right = smallerRight[i] - i;
            ans = (ans + (right*left*1ll*arr[i])%M)%M;
        }
        return ans;
    }
};