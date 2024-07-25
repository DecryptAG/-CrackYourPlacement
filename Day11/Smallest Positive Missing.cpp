// https://www.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    {   
        // for(int i =0;i<n;i++)
        //     cout<<arr[i]<<" ";
        // cout<<endl;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<0)
                arr[i] = 0;
        }
        // for(int i =0;i<n;i++)
        //     cout<<arr[i]<<" ";
        // cout<<endl;
        for(int i = 1;i<=n;i++)
        {
            int ind = abs(arr[i-1]) - 1;
            if(ind>=0 && ind<n)
            {   
                if(arr[ind]<0)
                    continue;
                if(arr[ind]!=0)
                    arr[ind] = -arr[ind];
                else
                    arr[ind] = -(n+1);
            }
        }
        // for(int i =0;i<n;i++)
        //     cout<<arr[i]<<" ";
        // cout<<endl;
        for(int i=1;i<=n;i++)
        {
            int ind = i - 1;
            if(ind>=0 && ind<n)
            {   
                if(arr[ind]<0)
                    continue;
                else
                    return i;
            }
        }
        return n+1;
        // Your code here
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends