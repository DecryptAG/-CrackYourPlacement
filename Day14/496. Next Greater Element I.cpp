// https://leetcode.com/problems/next-greater-element-i/description/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> st;
        unordered_map<int,int> mp;
        for(int i=n-1;i>=0;i--)
        {
            if(st.size()==0)
            {   
                mp[nums2[i]] = -1;
            }
            else{
                while(st.size()>0 && st.top()<=nums2[i])
                {
                    st.pop();
                }
                if(st.size()==0)
                    mp[nums2[i]] = -1;
                else
                {
                    mp[nums2[i]] = st.top();
                }
            }
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++)
        {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};