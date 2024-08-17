// https://leetcode.com/problems/simplify-path/description/

class Solution {
public:
    string simplifyPath(string s) {
        int n = s.size();
        stack<string> st;
        for(int i=0;i<n;i++)
        {   
            string temp = "";
            while(i<n && s[i]!='/')
            {
                temp+=s[i];
                i++;
            }
            if(temp.size()>0)
            {
                if(temp == "..")
                {
                    if(st.size()>0)
                        st.pop();
                }
                else if(temp == ".")
                    continue;
                else
                    st.push(temp);
            }
        }
        vector<string> ans;
        while(st.size()>0)
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        string ans_string = "/";
        for(int i=0;i<ans.size();i++)
        {
            ans_string+=ans[i];
            ans_string+='/';
        }
        if(ans.size()>0)
            ans_string.pop_back();
        return ans_string;
    }
};