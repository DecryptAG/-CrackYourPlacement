// https://www.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int n;
    bool isPalindrome(string s,int low, int high)
    {
        while(low<=high)
        {
            if(s[low]!=s[high])
                return false;
            low++;
            high--;
        }
        return true;
    }
    void solve(int ind,string s,vector<string> &ds, vector<vector<string>> &ans)
    {
        if(ind == n)
        {
            ans.push_back(ds);
            return;
        }
        for(int i = ind;i<n;i++)
        {
            if(isPalindrome(s,ind,i) == true)
            {
                ds.push_back(s.substr(ind,i-ind+1));
                solve(i+1,s,ds,ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string s) {
        // code here
        n = s.length();
        vector<vector<string>> ans;
        vector<string> ds;
        solve(0,s,ds,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends