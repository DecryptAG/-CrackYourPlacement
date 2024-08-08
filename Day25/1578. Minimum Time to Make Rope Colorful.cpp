// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i =0, j =0;
        int n = colors.size();
        int ans = 0;
        while(j<n)
        {
            if(colors[j]!=colors[i])
            {
                    int sum = 0;
                    int maxi = -1;
                    for(int k = i;k<j;k++)
                        {
                            sum = sum + neededTime[k];
                            maxi = max(maxi,neededTime[k]);
                        }
                    ans = ans + sum - maxi;
                i=j;
            }
            else
                j++;
        }
        if(i<j)
        {
            int sum = 0;
                    int maxi = -1;
                    for(int k = i;k<j;k++)
                        {
                            sum = sum + neededTime[k];
                            maxi = max(maxi,neededTime[k]);
                        }
                    ans = ans + sum - maxi;
                i=j;
        }
        return ans;
    }
};