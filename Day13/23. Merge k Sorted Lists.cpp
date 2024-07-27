// https://leetcode.com/problems/merge-k-sorted-lists/description/

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

class Comp{
    public:
    bool operator()(ListNode* a, ListNode* b)
    {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, Comp> pq;
        for(int i=0;i<n;i++)
        {   
            if(lists[i]!=NULL)
            pq.push(lists[i]);
        }
        if(pq.size()==0)
            return NULL;
        ListNode* head = new ListNode(-1);
        ListNode* temp1 = head;
        while(pq.size()>0)
        {   
            ListNode* mini = pq.top();
            pq.pop();
            ListNode* temp = new ListNode(mini->val);
            head->next = temp;
            head = head->next;
            if(mini->next!=NULL)
                pq.push(mini->next);
        }
        return temp1->next;
    }
};
//TC - O(n*klogk)
//SC - O(k) + O(k*n)

//This is not inplace