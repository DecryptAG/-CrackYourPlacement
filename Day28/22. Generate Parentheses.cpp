// https://leetcode.com/problems/generate-parentheses/description/

class Solution {
public:
    void solve(int open,int close,int n, string &str,vector<string> &ans)
    {   
        if(open==n && close==n)
        {
            ans.push_back(str);
            return;
        }
        if(open<n)
        {   
            str+="(";
            solve(open+1,close,n,str,ans);
            str.pop_back();
        }
        if(close<open)
        {   
            str+=")";
            solve(open,close+1,n,str,ans);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str = "";
        solve(0,0,n,str,ans);
        return ans;
    }
};