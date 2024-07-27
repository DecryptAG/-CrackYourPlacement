// https://leetcode.com/problems/reverse-linked-list-ii/description/

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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next == NULL)
            return head;
        ListNode* newHead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* back = new ListNode(-1);
        ListNode* backH = back;
        back->next = head;

        ListNode* leftHead = head;
        
        int t = left-1;
        while(t--)
        {
            leftHead = leftHead->next;
            back = back->next;
        }
        back->next = NULL;

        t = right - left;
        ListNode* rightHead = leftHead;
        while(t--)
        {
            rightHead = rightHead->next;
        }
        ListNode* front = rightHead->next;
        rightHead->next = NULL;
        ListNode* revHead = reverseList(leftHead);
        back->next = revHead;
        while(revHead->next !=NULL)
        {
            revHead = revHead->next;
        }
        revHead->next = front;
        return backH->next;
    }
};