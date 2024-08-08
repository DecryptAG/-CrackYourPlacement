// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/description/

class Solution {
public:
    int minDeletions(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        priority_queue<int> pq;
        for(auto it: mp)
        {
            pq.push(it.second);
        }
        int ans = 0;
        while(pq.size()>1)
        {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            if(x==y)
            {   
                ans++;
                x--;
                if(x>0)
                pq.push(x);
            }
            else continue;
        }
        return ans;
    }
};