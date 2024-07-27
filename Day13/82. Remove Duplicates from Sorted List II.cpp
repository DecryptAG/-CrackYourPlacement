// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next == NULL)
            return head;
        ListNode* curr = head;
        ListNode* prev = new ListNode(-1);
        ListNode* newHead = prev;
        int f = 0;
        while(curr!=NULL)
        {
            if(curr->next!=NULL && curr->val == curr->next->val)
            {
                f = 1;
                curr = curr->next;
                continue;
            }
            else if(f)
            {   
                f = 0;
                curr = curr->next;
            }
            else
            {
                prev -> next = curr;
                prev = prev->next;
                curr = curr->next;
                prev->next = NULL;
            }
        }
        return newHead->next;
    }
};