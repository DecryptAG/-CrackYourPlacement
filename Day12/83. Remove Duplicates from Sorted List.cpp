// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

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
    void deleteNode(ListNode* &prev, ListNode* &curr, ListNode* &next)
    {
        if(next==NULL)
        {
            curr = next;
            prev->next = curr;
        }
        else
        {
            curr = next;
            next = next->next;
            prev->next = curr;
        }
    }
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next==NULL)
            return head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;
        while(curr!=NULL)
        {
            if(prev->val == curr->val)
            {
                deleteNode(prev,curr,next);
            }
            else
            {
                prev = curr;
                curr= next;
                if(next!=NULL)
                {
                    next = next->next;
                }
            }
            
        }
        return head;
    }
};