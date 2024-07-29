// https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {   
        int totPetrol = 0, totDist = 0;
        for(int i=0;i<n;i++)
        {
            totPetrol+= p[i].petrol;
            totDist+= p[i].distance;
        }
        if(totPetrol<totDist)
            return -1;
        vector<int> diff;
        for(int i=0;i<n;i++)
        {
            diff.push_back(p[i].petrol-p[i].distance);
        }
        int g = 0, ind = 0;
        for(int i=0;i<n;i++)
        {
            if(g+diff[i]>=0)
            {
                g+=diff[i];
            }
            else
            {
                g = 0;
                ind = i+1;
            }
        }
        if(g>=0)
            return ind;
        return -1;
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
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends