// https://www.geeksforgeeks.org/problems/partition-array-to-k-subsets/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    bool solve(int ind,int k,int nums[], int n,vector<int> &mask,int target,int req)
    {  
        if(k==0)
            return true; 
        if(target == 0)
            return solve(0,k-1,nums,n,mask,req,req);

        for(int i=ind;i<n;i++)
        {   
            if(mask[i] == 0 && nums[i]<=target)
            {   
                mask[i] = 1;
                if(solve(i+1,k,nums,n,mask,target-nums[i],req) == true)
                    return true;
                mask[i] = 0;
            }
        }
        return false;
    }
    bool isKPartitionPossible(int nums[], int n, int k)
    {   
        vector<int> mask(n,0);
        int sum = accumulate(nums,nums+n,0);
        int maxi = *max_element(nums,nums+n);
        int target = sum/k;
        
        if(sum%k != 0  || maxi>target)
            return false;
        sort(nums,nums+n,greater<int>());
        return solve(0,k,nums,n,mask,target,target);
         //Your code here
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends