https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        if(head==NULL)
            return 0;
        string ans="";
        while(head!=NULL)
        {   
            if(head->val ==1)
                ans+="1";
            else
                ans+="0";
            head = head->next;
        }
        reverse(ans.begin(),ans.end());
        int res = 0;
        for(int i=0;i<ans.length();i++)
        {
            res+=(pow(2,i)*(ans[i]-'0'));
        }
        return res;
    }
};