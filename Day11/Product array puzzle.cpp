// https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here       
        if(n==1)
            return {1ll};
        vector<long long> pre(n,0);
        vector<long long> suf(n,0);
        pre[0 ]= nums[0];
        suf[n-1] = nums[n-1];
        for(int i=1;i<n;i++)
        {
            pre[i] = pre[i-1]*nums[i];
            suf[n-i-1] = suf[n-i]*nums[n-i-1];
        }
        vector<long long> ans(n,0);
        for(int i=0;i<n;i++)
        {
            if(i>0 && i<n-1)
            {
                ans[i] = pre[i-1]*suf[i+1];
            }
            else if(i==0)
            {
                ans[i] = suf[1];
            }
            else
            {
                ans[i] = pre[n-2];
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends