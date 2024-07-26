// https://leetcode.com/problems/palindrome-linked-list/description/

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
    ListNode* reverseList(ListNode* head)
    {   
        ListNode *p = NULL;
        ListNode *c = head;
        ListNode *n = head->next;
        while(c!=NULL)
        {
            c->next = p;
            p = c;
            c = n;
            if(n!=NULL)
                n=n->next;
        }
        return p;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL)
            return true;
        ListNode* temp = head;
        int c = 0;
        while(temp!=NULL)
        {
            temp=temp->next;
            c++;
        }
        if(c==1)
            return true;
        else if(c==2)
            return head->val==head->next->val;
        else
        {
            ListNode *rev;
            if(c%2==0)
            {   
                int t = c/2-1;
                ListNode* mid = head;
                while(t--)
                {
                    mid = mid->next;
                }
                rev = reverseList(mid);
            }
            else
            {
                int t = c/2-1;
                ListNode* mid = head;
                while(t--)
                {
                    mid = mid->next;
                }
                mid = mid->next;
                rev = reverseList(mid);
            }
            while(head!=NULL)
            {
                if(head->val!=rev->val)
                    return false;
                head = head->next;
                rev = rev->next;
            }
        }
        return true;
    }
};