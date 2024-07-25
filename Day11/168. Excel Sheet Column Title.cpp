// https://leetcode.com/problems/excel-sheet-column-title/description/

class Solution {
public:
    string convertToTitle(int nums) {
        string ans = "";
        int temp = nums;
        int ind = 1;
        while(temp>0)
        {       
            cout<<temp<<"temp"<<endl;
            int rem = temp%26;
            if(rem == 0)
            {
                ans+='Z';
                temp = temp - 26;
            }    
            else
            {
                ans+=('A'+rem-1);
                temp = temp-rem;
            }
            int x = temp/26;
            temp = x;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};