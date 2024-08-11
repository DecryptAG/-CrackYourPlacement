// https://www.geeksforgeeks.org/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum-set-2/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts
                               //Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int totSum;
    void solve(int i,vector<int> &arr, int n,int count, vector<vector<int>> &ans, int currSum, int &mini)
    {   
        if(count == (n+1)/2)
        {
            if(abs(currSum-(totSum-currSum)) < mini)
            {
                mini = abs(currSum-(totSum-currSum)) ;
                ans[0][0] = currSum;
                ans[1][0] = (totSum-currSum);
            }
        }
        if(i==n)
            return;
        solve(i+1,arr,n,count+1,ans,currSum+arr[i],mini);
        solve(i+1,arr,n,count,ans,currSum,mini);
    }
     vector<vector<int>> minDifference(vector<int>& arr, int n){
        //Code here
        vector<vector<int>> ans(2,vector<int>(1,0));
        totSum = accumulate(arr.begin(),arr.end(),0);
        int mini = INT_MAX;
        solve(0,arr,n,0,ans,0,mini);
        return ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        vector<vector<int>> ans = obj.minDifference(arr,n);
        
        long long s1=0, s2=0;

        for(int i=0;i<ans[0].size();i++) s1+=ans[0][i];
        for(int i=0;i<ans[1].size();i++) s2+=ans[1][i];
        
        if(s1>s2) swap(s1,s2);

        cout<<s1<<"\n"<<s2<<"\n";
    }
}
                               
// } Driver Code Ends