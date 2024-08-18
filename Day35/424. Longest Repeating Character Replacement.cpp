// https://leetcode.com/problems/longest-repeating-character-replacement/description/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int ans = 0;
        for(char i = 'A';i<='Z';i++)
        {
            for(int j =0;j<n;j++)
            {   
                int temp = k;
                if(s[j] == i)
                {   
                    int t = j;
                    int c = 0;
                    while(j<n && (s[j]==i || temp>0))
                    {   
                        c++;
                        if(s[j]!=i)
                            temp--;
                        j++;
                    }
                    if(temp>0)
                    ans = max(ans,min(n,c+temp));
                    else
                    ans = max(ans,c);
                    j = t;
                }
            }
        }
        return ans;
    }
};