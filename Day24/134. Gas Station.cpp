// https://leetcode.com/problems/gas-station/description/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totGas = accumulate(gas.begin(),gas.end(),0);
        int totCost = accumulate(cost.begin(),cost.end(),0);
        if(totGas<totCost)
            return -1;
        vector<int> diff;
        for(int i=0;i<n;i++)
        {
            diff.push_back(gas[i]-cost[i]);
        }
        int g = 0, ind = 0;
        for(int i=0;i<n;i++)
        {
            if(g+diff[i]>=0)
            {
                g+=diff[i];
            }
            else
            {
                g = 0;
                ind = i+1;
            }
        }
        if(g>=0)
            return ind;
        return -1;
    }
};