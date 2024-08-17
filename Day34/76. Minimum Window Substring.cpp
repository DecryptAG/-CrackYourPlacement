// https://leetcode.com/problems/minimum-window-substring/description/

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        int i=0, j=0;
        map<char,int> mp,mp1;
        for(int i=0;i<m;i++)
        {
            mp[t[i]]++;
        }
        int req = 0;
        string str = "";
        string ans = s+t;
        string temp = s+t;
        while(j<n && i<n)
        {   
            // cout<<i<<j<<endl;
            mp1[s[j]]++;
            str+=s[j];
            int flag = 0;
            for(auto it: mp)
            {
                if(it.second > mp1[it.first])
                    {
                        flag=1;
                        break;
                    }
            }
            if(flag==0)
            {   
                while(flag==0)
                {   
                    if(str.length()<=ans.length())
                        ans = str;
                    // cout<<ans<<endl;
                    mp1[s[i]]--;
                    i++;
                    if(str.length()>0)
                        str.erase(str.begin());
                    for(auto it: mp)
                    {   
                        if(it.second > mp1[it.first])
                            {
                                flag=1;
                                break;
                            }
                    }
                }
            }
            j++;
        }
        // cout<<ans<<endl;
        if(ans == (temp))
            return "";
        return ans;
    }
};