// https://leetcode.com/problems/daily-temperatures/description/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> greater;
        stack<pair<int,int>> st;
        for(int i = n-1;i>=0;i--)
        {   
            if(st.size()==0)
                greater.push_back(0);
            else if(st.size()>0 && st.top().first>temperatures[i])
            {
                greater.push_back(st.top().second);
            }
            else
            {
                while(st.size()>0 && st.top().first<=temperatures[i])
                {
                    st.pop();
                }
                if(st.size()==0)
                {
                    greater.push_back(0);
                }
                else
                {
                    greater.push_back(st.top().second);
                }
            }
            st.push({temperatures[i],i});
        }
        reverse(greater.begin(),greater.end());
        for(int i=0;i<n;i++)
        {
            if(greater[i]!=0)
                greater[i] = greater[i] - i;
        }
        return greater;
    }
};