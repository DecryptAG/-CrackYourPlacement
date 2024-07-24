// https://leetcode.com/problems/reverse-pairs/description/

class Solution {
public:
    int countPair(vector<int> &arr, int low, int mid, int high)
    {   
        int right = mid+1;
        int count = 0;
        int c = 0;
        for(int i = low;i<=mid;i++)
        {
            while(right<=high)
            {
                if(arr[i]*1ll> 2*1ll*arr[right])
                {
                    c++;
                    right++;
                }
                else
                    break;
            }
            count+=c;
        }
        return count;
    }
    void merge(vector<int> &arr,int low, int mid, int high)
    {
        vector<int> temp;
        int left = low;
        int right = mid+1;
        while(left<=mid && right<=high)
        {
            if(arr[left]<arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid)
        {
            temp.push_back(arr[left]);
                left++;
        }
        while(right<=high)
        {
            temp.push_back(arr[right]);
                right++;
        }
        for(int i = low ;i<=high;i++)
        {
            arr[i] = temp[i-low];
        }
    }
    int mergeSort(vector<int> &arr, int low, int high)
    {
        if(low>=high)
            return 0;
        int mid = (low+high)/2;
        int count = 0;
        count+=mergeSort(arr,low,mid);
        count+=mergeSort(arr,mid+1,high);
        count+=countPair(arr,low,mid,high);
        merge(arr,low,mid,high);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums,0,n-1);
        // return count;
    }
};