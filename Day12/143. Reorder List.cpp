// https://leetcode.com/problems/reorder-list/description/

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
        if(head==NULL)
            return head;
        ListNode *p = NULL, *c = head, *n = head->next;
        while(c!=NULL)
        {
            c->next = p;
            p = c;
            c= n;
            if(n!=NULL)
                n = n->next;
        }
        return p;
    }
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return;
        ListNode *slow = head, *fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow = slow->next;
            if(fast->next!=NULL)
                fast = fast->next->next;
        }
        ListNode* middle = slow->next;
        slow->next = NULL;
        ListNode* j = reverseList(middle);
        ListNode* i = head;
        ListNode* dummy = i;
        ListNode* dummy1 = j;
        while(i!=NULL)
        {   
            cout<<i->val<<endl; 
            i = i->next;
            dummy->next = dummy1;
            if(j!=NULL)
                j = j->next;
            if(dummy1!=NULL)
                dummy1->next = i;
            dummy = i;
            dummy1 = j;
        }
        if(dummy!=NULL)
        {
            dummy1->next = dummy;
        }
    }
};