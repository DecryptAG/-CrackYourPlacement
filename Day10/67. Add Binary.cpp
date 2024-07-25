// https://leetcode.com/problems/add-binary/description/

class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length();
        int m = b.length();
        if(n>m)
            return addBinary(b,a);
        reverse(a.begin(),a.end());
        reverse(begin(b),end(b));
        string carry = "0";
        string ans = "";
        for(int i=0;i<n;i++)
        {
            if(a[i] == b[i] && a[i] == '1')
            {
                if(carry == "1")
                {
                    ans+="1";
                    carry = "1";
                }
                else
                {
                    ans+="0";
                    carry = "1";
                }
            }
            else if(a[i] == b[i] && a[i] == '0')
            {
                if(carry == "1")
                {
                    ans+="1";
                    carry = "0";
                }
                else
                {
                    ans+="0";
                    carry = "0";
                }
            }
            else
            {
                if(carry == "1")
                {
                    ans+="0";
                    carry = "1";
                }
                else
                {
                    ans+="1";
                    carry = "0";
                }
            }
        }
        int j = n;
        while(j<m)
        {
            if(b[j] == '1')
            {
                if(carry == "1")
                {
                    ans+="0";
                    carry = "1";
                }
                else
                {
                    ans+="1";
                    carry = "0";
                }
            }
            else
            {
                if(carry == "1")
                {
                    ans+="1";
                    carry = "0";
                }
                else
                {
                    ans+="0";
                    carry = "0";
                }
            }
            j++;
        }
        if(carry == "1")
            ans+="1";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};