// https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
            }
            else if(s[i]==')')
            {
                if(st.size()!=0)
                {
                    if(st.top()=='(')
                        st.pop();
                    else
                        return false;
                }
                else
                {
                    return false;
                }
            }
            else if(s[i]=='}')
            {
                if(st.size()!=0)
                {
                    if(st.top()=='{')
                        st.pop();
                    else
                        return false;
                }
                else
                {
                    return false;
                }
            }
            else if(s[i]==']')
            {
                if(st.size()!=0)
                {
                    if(st.top()=='[')
                        st.pop();
                    else
                        return false;
                }
                else
                {
                    return false;
                }
            }
        }
        if(st.size()==0)
            return true;
        return false;
    }
};