// https://leetcode.com/problems/odd-even-linked-list/description/

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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *join = head->next,*Even = head->next;
        ListNode *Odd = head;

        while(Odd!=NULL && Even!=NULL && Even->next!= NULL && Odd->next!= NULL)
        {
            Odd->next = Even->next;
            Even->next = Odd->next->next;
            Odd = Odd->next;
            Even = Even->next;
        }
        Odd->next = join;
        return head;
    }
};