// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
            return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* p = dummy;
        ListNode* nxt = dummy;
        for(int i=0;i<n;i++)
            nxt = nxt->next;
        while(nxt->next != nullptr)
        {   
            nxt = nxt->next;
            p = p->next;
        }
        ListNode* t = p->next;
        if(t)
            p->next = t->next;
        else
            p->next = nullptr;
        delete(t);
        return dummy->next;
    }
};