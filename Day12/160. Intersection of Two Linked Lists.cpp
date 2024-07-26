// https://leetcode.com/problems/intersection-of-two-linked-lists/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tailA = headA, *tailB = headB;
        int l1 = 1,l2 = 1;
        while(tailA->next!=NULL || tailB->next!=NULL)
        {
            if(tailA->next)
                {
                    tailA= tailA->next;
                    l1++;
                }
            if(tailB->next)
                {
                    tailB= tailB->next;
                    l2++;
                }
                
        }
        if(tailA!=tailB)
            return NULL;
        else
        {
            if(l2>l1)
            {   
                int diff = l2-l1;
                while(diff--)
                {
                    headB=headB->next;
                }
            }
            else
            {
                int diff = l1-l2;
                while(diff--)
                {
                    headA=headA->next;
                }
            }
            while(headA!=NULL && headB!=NULL)
            {
                if(headA==headB)
                    return headA;
                headA= headA->next;
                headB= headB->next;
            }
        }
        return NULL;
    }
};