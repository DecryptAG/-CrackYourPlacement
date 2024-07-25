// https://leetcode.com/problems/split-array-largest-sum/description/

class Solution {
public:
    int check(vector<int> &arr, int n, int m , int mid)
    {
        int c = 1;
        long long sum = 0;
        for(int i=0;i<n;i++)
        {   
            if(sum+arr[i]<=mid)
            {
                sum+=arr[i];
            }
            else
            {  
                if(sum<=mid)   
                    c++;
                sum = arr[i];
            }
        }
        // cout<<c<<"c"<<endl;
        return c;
            
    }
    int splitArray(vector<int>& arr, int m) {
        int n = arr.size();
        int l = *max_element(arr.begin(),arr.end());
        int h = accumulate(arr.begin(),arr.end(),0);
        int ans = 0;
        while(l<=h)
        {
            int mid = l + (h-l)/2;
            // cout<<l<<" "<<h<<endl;
            // cout<<"mid"<<mid<<endl;
            int k = check(arr,n,m,mid);
            // cout<<k<<"k"<<endl;
            if(k<=m)
            {
                ans = mid;
                h = mid-1;
            }
            else
            {
                l = mid+1;
            }
            // else
            // {
            //     h = mid-1;
            // }
        }
        return ans;
    }
};
