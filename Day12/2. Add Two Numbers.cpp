// https://leetcode.com/problems/add-two-numbers/description/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr = new ListNode(-1);
        ListNode* temp = ptr;
        int carry = 0;
        while(l1!=NULL && l2!=NULL)
        {
            int x = l1->val+l2->val+carry;
            ptr->next = new ListNode(x%10);
            carry = x/10;
            l1=l1->next;
            l2=l2->next;
            ptr=ptr->next;
        }
        while(l1!=NULL)
        {
            int x = l1->val+carry;
            ptr->next = new ListNode(x%10);
            carry = x/10;
            l1=l1->next;
            ptr=ptr->next;
        }
        while(l2!=NULL)
        {
            int x = l2->val+carry;
            ptr->next = new ListNode(x%10);
            carry = x/10;
            l2=l2->next;
            ptr=ptr->next;
        }
        if(carry)
            ptr->next = new ListNode(1);
        return temp->next;
    }
};