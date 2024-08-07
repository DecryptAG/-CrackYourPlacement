// https://leetcode.com/problems/find-the-most-competitive-subsequence/description/

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        stack<int> st;
        int t = n-k;
        for(int i=0;i<n;i++)
        {
            int d = nums[i];
            while(st.size()>0 && t>0 && st.top()>d)
            {   
                st.pop();
                t--;
            }
            st.push(d);
        }
        vector<int> ans;
        while (t > 0 && !st.empty()) {
            st.pop();
            t--;
        }
        while(st.size()>0)
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};