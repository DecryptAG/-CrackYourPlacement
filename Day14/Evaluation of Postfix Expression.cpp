// https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1

//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    {   
        stack<int> st;
        for(int i = 0;i<s.length();i++)
        {   
            int n = s[i] - '0';
            if(n<10 && n>=0)
            {
                st.push(n);
            }
            else
            {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                int ans = 0;
                if(s[i] == '+')
                {
                    ans = x+y;
                }
                else if(s[i] == '-')
                {
                    ans = y-x;
                }
                else if(s[i] == '/')
                ans = y/x;
                else
                ans = x*y;
                st.push(ans);
            }
        }
        return st.top();
        // Your code here
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends