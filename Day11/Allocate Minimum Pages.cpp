// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to find minimum number of pages.
    int check(int arr[], int m, int mid,int n)
    {   
        long long sum = 0;
        int c = 1;
        for(int i=0;i<n;i++)
        {   
            if(sum+arr[i]<=mid)
            {
                sum+=arr[i];
            }
            else
            {   
                c++;
                sum = arr[i];
            }
        }
        return c;
        
    }
    long long findPages(int n, int arr[], int m) {
        // code here
        // sort(arr,arr+n);
        if(m>n)
            return -1;
        long long low = *max_element(arr,arr+n);
        long long high = accumulate(arr,arr+n,0ll);
        long long ans = 0;
        while(low<=high)
        {
            long long mid = low + (high-low)/2;
            int k = check(arr,m,mid,n);
            if(k<=m)
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends