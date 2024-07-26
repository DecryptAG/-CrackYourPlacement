// https://leetcode.com/problems/merge-two-sorted-lists/description/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *s1 = list1;
        ListNode *s2 = list2;
        ListNode *head = new ListNode;
        if(s1==NULL)
        {
            return s2;
        }
        if(s2==NULL)
        {
            return s1;
        }
        if(s1->val<=s2->val)
            {
                head = s1;
                s1 = s1->next;
            }
        else
            {
                head = s2;
                s2 = s2->next;
            }
        ListNode *tail = head;
        while(s1!=NULL && s2!=NULL)
        {
            if(s1->val<=s2->val)
            {
                tail->next = s1;
                s1 = s1->next;
            }
            else
            {
                tail->next = s2;
                s2 = s2->next;
            }
            tail = tail->next;
        }
        if(s1!=NULL)
        {
            tail->next = s1;
        }
        else if(s2!=NULL)
        {
            tail->next = s2;
        }
        return head;
    }
};