// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        stack<char> st;
        stack<int> count;
        for(int i=0;i<n;i++)
        {
            if(st.size()>0)
            {
                if(st.top()==s[i])
                {
                    int x = count.top();
                    count.pop();
                    count.push(x+1);
                    st.push(s[i]);
                }
                else
                {   
                    st.push(s[i]);
                    count.push(1);
                }
                if(count.top()==k)
                {   
                    int x = count.top();
                    count.pop();
                    while(x--)
                    {
                        st.pop();
                    }
                }
            }
            else
            {
                st.push(s[i]);
                count.push(1);
            }
        }
        string ans = "";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};