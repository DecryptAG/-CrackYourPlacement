// https://www.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    int n;
    void solve(int ind,string &str,int k,string &ans)
    {
        if(ind >= n || k==0)
        {
          ans = max(ans,str); 
           return;
        }
        for(int i = ind+1;i<n;i++)
        {   
            if(str[i]>str[ind])
            {
                swap(str[ind],str[i]);
                solve(ind+1,str,k-1,ans);
                swap(str[ind],str[i]);
            }
        }
        solve(ind+1,str,k,ans);
    }
    string findMaximumNum(string str, int k)
    {   
        n = str.length();
        string ans = "";
        solve(0,str,k,ans);
        return ans;
    }
};

// 4551711527
// 7551711524
// 7751511524


//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends