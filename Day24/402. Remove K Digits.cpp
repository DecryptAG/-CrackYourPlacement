// https://leetcode.com/problems/remove-k-digits/description/

class Solution {
public:
    string removeKdigits(string s, int k) {
        int n = s.length();
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            char d = s[i];
            while(st.size()>0 && k>0 && st.top()>d)
            {   
                st.pop();
                k--;
            }
            st.push(d);
        }
        string ans = "";
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        while(st.size()>0)
        {
            ans+=st.top();
            st.pop();
        }
        cout<<ans<<endl;
        reverse(ans.begin(),ans.end());
        int ind = -1;
        for(int i=0;i<n;i++)
        {
            if(ans[i]!='0')
            {
                ind = i;
                break;
            }
        }
        if(ind!=-1 && ans.length()>ind)
            ans.erase(0,ind);
        else
            return "0";
        return ans;
    }
};