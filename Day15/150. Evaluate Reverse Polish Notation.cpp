// https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        for(int i=0;i<n;i++)
        {
            if(tokens[i]=="+")
            {
                if(st.size()>1)
                {
                    int x = st.top();
                    st.pop();
                    int y = st.top();
                    st.pop();
                    st.push(x+y);
                }
            }
            else if(tokens[i]=="-")
            {
                if(st.size()>1)
                {
                    int x = st.top();
                    st.pop();
                    int y = st.top();
                    st.pop();
                    st.push(y-x);
                }
            }
            else if(tokens[i]=="/")
            {
                if(st.size()>1)
                {
                    int x = st.top();
                    st.pop();
                    int y = st.top();
                    st.pop();
                    st.push(y/x);
                }
            }
            else if(tokens[i]=="*")
            {
                if(st.size()>1)
                {
                    int x = st.top();
                    st.pop();
                    int y = st.top();
                    st.pop();
                    st.push(x*y);
                }
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
