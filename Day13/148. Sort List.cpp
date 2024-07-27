// https://leetcode.com/problems/sort-list/description/

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
    ListNode* merge(ListNode* left, ListNode* right)
    {
        ListNode* s1 = left;
        ListNode* s2 = right;
        ListNode* dummy = new ListNode(-1);
        ListNode* Head = dummy;
        while(s1!=NULL && s2!=NULL)
        {
            if(s1->val < s2->val)
            {
                dummy->next = s1;
                s1 = s1->next;
                dummy = dummy->next;
                dummy->next = NULL;
            }
            else
            {
                dummy->next = s2;
                s2 = s2->next;
                dummy = dummy->next;
                dummy->next = NULL;
            }
        }
        if(s1!=NULL)
            dummy->next = s1;
        if(s2!=NULL)
            dummy->next = s2;
        return Head->next;
    }
    ListNode* findMiddle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergeSort(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* mid = findMiddle(head);
        ListNode* leftHead = head;
        ListNode* rightHead = mid->next;
        mid->next = NULL;
        ListNode* left = mergeSort(leftHead);
        ListNode* right = mergeSort(rightHead);
        return merge(left,right);
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};