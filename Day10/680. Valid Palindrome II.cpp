// https://leetcode.com/problems/valid-palindrome-ii/description/

class Solution {
public:
    bool isPalin(string s, int i, int j)
    {
        int c=0;
        while(i<=j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
            {
                return 0;
            }
        }
        return 1;
    }
    bool validPalindrome(string s) {
        int n = s.length();
        int i=0,j=n-1;
        int c=0;
        while(i<=j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
            {
                return isPalin(s,i+1,j)||isPalin(s,i,j-1);
            }
        }
        return 1;
    }
};