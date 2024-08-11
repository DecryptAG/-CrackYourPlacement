// https://leetcode.com/problems/reverse-words-in-a-string/description/

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int start = 0, end = n-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=' ')
                {
                    start = i;
                    break;
                }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]!=' ')
                {
                    end = i;
                    break;
                }
        }
        s = s.substr(start,end-start+1);
        reverse(s.begin(),s.end());
        s+=" ";
        string ans = "";
        n = s.length();
        for(int i=0;i<n;i++)
        {   
            string temp = "";
            while(s[i]!=' ' && i<n)
            {
                temp+=s[i];
                i++;
            }
            reverse(temp.begin(),temp.end());
            if(temp.size()>0)
            {   ans+=temp;
                if(i != n-1)
                {
                    // cout<<i<<endl;
                    ans+=" ";
                }    
            }
        }
        return ans;
    }
};