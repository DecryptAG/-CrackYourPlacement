// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        // Your code here
        unordered_map<int,int> mp;
        mp[0] = -1;
        int a = 0;
        for(int i=0;i<n;i++)
        {
            a+=arr[i];
            if(mp.find(a)==mp.end())
            {
                mp[a] = i;
            }
        }
        int ans = INT_MIN;
        a = 0;
        for(int i=0;i<n;i++)
        {   
            a+=arr[i];
            ans = max(ans,i - mp[a]);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends