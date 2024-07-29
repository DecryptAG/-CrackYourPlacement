// https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1

// read iska gfg article and brocoders video and divya kumar video


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {   
        vector<int> smallerRight, smallerLeft;
        stack<pair<int,int>> st;
        for(int i = n-1;i>=0;i--)
        {
            if(st.size()==0)
            {
                smallerRight.push_back(-1);
            }
            else if(st.size()>0 && st.top().first < arr[i])
            {
                smallerRight.push_back(st.top().second);
            }
            else if(st.size()>0 && st.top().first >= arr[i])
            {
                while(st.size()>0 && st.top().first >= arr[i])
                {
                    st.pop();
                }
                if(st.size()==0)
                {
                    smallerRight.push_back(-1);
                }
                else
                {
                    smallerRight.push_back(st.top().second);
                }
            }
            st.push({arr[i],i});
        }
        for(int i=0;i<n;i++)
        {
            if(smallerRight[i] == -1)
                smallerRight[i] = n;
        }
        reverse(smallerRight.begin(),smallerRight.end());
        while(!st.empty())
            st.pop();
        for(int i = 0;i<n;i++)
        {
            if(st.size()==0)
            {
                smallerLeft.push_back(-1);
            }
            else if(st.size()>0 && st.top().first < arr[i])
            {
                smallerLeft.push_back(st.top().second);
            }
            else if(st.size()>0 && st.top().first >= arr[i])
            {
                while(st.size()>0 && st.top().first >= arr[i])
                {
                    st.pop();
                }
                if(st.size()==0)
                {
                    smallerLeft.push_back(-1);
                }
                else
                {
                    smallerLeft.push_back(st.top().second);
                }
            }
            st.push({arr[i],i});
        }
        vector<int> ans(n,0);
        for(int i=0;i<n;i++)
        {
            ans[smallerRight[i] - smallerLeft[i] - 2] = max(ans[smallerRight[i] - smallerLeft[i] - 2],arr[i]); 
        }
        for(int i = n-2; i>=0 ;i--)
        {
            ans[i] = max(ans[i],ans[i+1]);
        }
        return ans;
        // Your code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends