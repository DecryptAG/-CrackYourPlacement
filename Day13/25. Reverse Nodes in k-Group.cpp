// https://leetcode.com/problems/reverse-nodes-in-k-group/description/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* headD = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* dummyH = dummy;
        ListNode* hd = head;
        ListNode* nxt = NULL;
        int c = 1;
        while(headD!=NULL)
        {
            if(c<k)
            {
                headD = headD->next;
                c++;
                continue;
            }
            else
            {
                nxt = headD->next;
                headD->next = NULL;
                ListNode* newHead = reverse(hd);
                hd = nxt;
                dummy->next = newHead;
                while(dummy->next!=NULL)
                {
                    dummy = dummy->next;
                }
                c = 1;
                headD = nxt;
            }
        }
        dummy->next = nxt;
        return dummyH->next;
    }
};