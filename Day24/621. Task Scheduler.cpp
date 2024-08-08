// https://leetcode.com/problems/task-scheduler/description/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> mp;
        int size = tasks.size();
        for(int i=0;i<size;i++)
        {
            mp[tasks[i]]++;
        }
        for(auto it: mp)
        {
            pq.push({it.second,it.first});
        }
        //task //count //time
        queue<pair<char,pair<int,int>>> q;
        int time = 1;
        while(pq.size()>0 || q.size()>0)
        {
            if(pq.size()>0)
            {
                auto it = pq.top();
                pq.pop();
                it.first--;
                if(it.first>0)
                    q.push({it.second,{it.first,time+n}});
            }
            if(q.size()>0)
            {
                if(q.front().second.second == time)
                {
                    auto it = q.front();
                    q.pop();
                    pq.push({it.second.first,it.first});
                }
            }
            time++;
        }
        time--;
        return time;
    }
};