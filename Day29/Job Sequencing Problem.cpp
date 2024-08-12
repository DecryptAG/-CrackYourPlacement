// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    {   
        //profit deadline id
        sort(arr,arr+n,[](Job a,Job b){
            return a.profit > b.profit;
        });
        int max_dead=0;
        for(int i =0;i<n;i++)
        {
            int x = arr[i].id;
            int y = arr[i].dead;
            int z = arr[i].profit;
            max_dead = max(max_dead,y);
        }
        vector<int> vec(max_dead+1,-1);
        int max_profit = 0;
        int i = 0;
        while(i<n)
        {   
            int profit = arr[i].profit;
            int id = arr[i].id;
            int deadline = arr[i].dead;
            if(vec[deadline]<profit)
            {   
                vec[deadline] = profit;
                max_profit+=profit;
            }
            else
            {   
                while(deadline>0)
                {
                    if(vec[deadline]<profit)
                    {   
                        vec[deadline] = profit;
                        max_profit+=profit;
                        break;
                    }
                    deadline--;
                }
            }
            i++;
        }
        int c=0;
        for(int i=1;i<max_dead+1;i++)
        {   
            if(vec[i]==-1)
            {
                c++;
            }
        }
        return {max_dead-c,max_profit};
        // your code here
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends