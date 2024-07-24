// https://leetcode.com/problems/longest-common-prefix/description/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int i=1;i<strs.size();i++)
        {
            int n = ans.length();
            int m = strs[i].length();
            int mini = min(n,m);
            int j = 0;
            string temp = "";
            while(j < mini)
            {
                if(strs[i][j] == ans[j])
                {
                    temp = temp + ans[j];
                }
                else
                {
                    break;
                }
                j++;
            }
            ans = temp;
        }
        return ans;
    }
};