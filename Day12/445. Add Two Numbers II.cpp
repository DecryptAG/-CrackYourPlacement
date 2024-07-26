// https://leetcode.com/problems/add-two-numbers-ii/description/

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
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* newHead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;

    }
    ListNode* aux(ListNode* l1, ListNode* l2) {
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* r1 = reverse(l1);
        ListNode* r2 = reverse(l2);
        ListNode* rev = aux(r1,r2);
        return reverse(rev);
    }
};