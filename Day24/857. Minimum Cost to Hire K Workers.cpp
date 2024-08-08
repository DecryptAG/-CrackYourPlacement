// https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double,int>> vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back({(wage[i]*1.0)/quality[i],quality[i]});
        }
        sort(vec.begin(),vec.end());
        priority_queue<int> pq;
        int totalQuality = 0;
        double res = INT_MAX;
        for(int i=0;i<n;i++)
        {   
            double rate = vec[i].first;
            totalQuality+= vec[i].second;
            pq.push(vec[i].second);
            if(pq.size() > k)
            {
                totalQuality-=pq.top();
                pq.pop();
            }
            if(pq.size()==k)
            {
                res = min(res,totalQuality*rate);
            }
        }
        return res;
    }
};