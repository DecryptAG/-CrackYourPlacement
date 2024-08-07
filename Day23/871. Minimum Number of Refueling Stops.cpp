// https://leetcode.com/problems/minimum-number-of-refueling-stops/description/

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        priority_queue<int> pq;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(startFuel >= stations[i][0])
            {
                pq.push(stations[i][1]);
            }
            else if(pq.size()>0)
            {   
                while(pq.size()>0 && startFuel < stations[i][0])
                {   
                    ans++;
                    startFuel+=pq.top();
                    pq.pop();
                }
                if(startFuel >= stations[i][0])
                    pq.push(stations[i][1]);
                else if(pq.size()==0 && startFuel < stations[i][0])
                    return -1;
            }
        }
        if(startFuel >= target)
        {
            return ans;
        }
        while(pq.size()>0 && startFuel < target)
        {
            ans++;
            startFuel+=pq.top();
            pq.pop();
        }
        if(startFuel >= target)
            return ans;
        return -1;
    }
};