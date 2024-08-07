// https://leetcode.com/problems/reorganize-string/description/

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++)
        {   
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto it: mp)
        {   
            if(it.second > (n+1)/2)
                return "";
            pq.push({it.second,char(it.first)});
        }
        string ans = "";
        while(pq.size()>1)
        {
            auto x = pq.top();
            pq.pop();
            auto y = pq.top();
            pq.pop();
            // cout<<x.second<<" "<<y.second<<endl;
            ans+=x.second;
            ans+=y.second;
            if(x.first > 1)
                pq.push({x.first-1,x.second});
            if(y.first > 1)
                pq.push({y.first-1,y.second});
        }
        if(pq.size()==1)
        {   
            // cout<<pq.top().second<<" "<<pq.top().first<<endl;
            ans+=pq.top().second;
        }
        return ans;
    }
};