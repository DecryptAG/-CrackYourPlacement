// https://leetcode.com/problems/partition-list/description/

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
    ListNode* reverse(ListNode* head)
    {
        if(head==NULL || head->next ==NULL)
            return head;
        ListNode* newHead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }
    ListNode* partition(ListNode* head, int x) {
        ListNode* headD = reverse(head);
        ListNode* smallD = new ListNode(-1);
        ListNode* small = smallD;
        ListNode* bigD = new ListNode(-1);
        ListNode* big = bigD;
        while(headD!=NULL)
        {
            if(headD->val < x)
            {
                smallD->next = headD;
                headD = headD->next;
                smallD = smallD->next;
                smallD->next = nullptr;
            }
            else
            {
                bigD->next = headD;
                headD = headD->next;
                bigD = bigD->next;
                bigD->next = nullptr;
            }
        }
        bigD->next = small->next;
        return reverse(big->next);
        
        
    }
};