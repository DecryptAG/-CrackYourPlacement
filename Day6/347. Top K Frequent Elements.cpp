// https://leetcode.com/problems/top-k-frequent-elements/description/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i =0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto it: mp)
        {
            if(pq.size()<k)
                pq.push({it.second,it.first});
            else if(pq.top().first<it.second)
            {
                pq.pop();
                pq.push({it.second,it.first});
            }
        }
        vector<int> ans;
        while(pq.size()>0)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};