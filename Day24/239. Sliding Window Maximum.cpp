// https://leetcode.com/problems/sliding-window-maximum/description/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> st;
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            st.insert(nums[i]);
        }
        ans.push_back(*(st.rbegin()));
        int i = 0,j =k;
        while(j<n && i<n)
        {
            st.insert(nums[j]);
            auto it = st.find(nums[i]);
            if(it!=st.end())
            {   
                st.erase(it);
            }
            ans.push_back(*(st.rbegin()));
            j++;
            i++;
        }
        return ans;
    }
};