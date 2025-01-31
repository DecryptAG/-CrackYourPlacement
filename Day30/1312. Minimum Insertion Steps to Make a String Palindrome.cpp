// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

class Solution {
public:
    int palindrome(string str, string temp)
    {   int n = str.length();
        int t[n+1][n+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0 || j==0)
                    t[i][j] = 0;
            }
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(str[i-1] == temp[j-1])
                {
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else
                {
                    t[i][j] = max(t[i-1][j] , t[i][j-1]);
                }
            }
        }
        return t[n][n];
    }
    int minInsertions(string s) {
        string temp = s ;
        reverse(temp.begin(),temp.end());
        int palLength = palindrome(s,temp);
        return s.length() - palLength ;
    }
};