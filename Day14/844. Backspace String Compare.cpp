// https://leetcode.com/problems/backspace-string-compare/description/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {   
            if(s[i]=='#')
            {
                if(st.size()>0)
                    st.pop();
            }
            else
                st.push(s[i]);
        }
        string s1 = "";
        while(!st.empty())
        {
            s1.push_back(st.top());
            st.pop();
        }
        for(int i=0;i<t.length();i++)
        {   
            if(t[i]=='#')
            {
                if(st.size()>0)
                    st.pop();
            }
            else
                st.push(t[i]);
        }
        string s2 = "";
        while(!st.empty())
        {
            s2.push_back(st.top());
            st.pop();
        }
        return s1==s2;
    }
};