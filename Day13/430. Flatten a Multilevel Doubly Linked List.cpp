// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:

    Node* flatten(Node* head) {
        if(head==NULL || (head->next == NULL && head->child==NULL))
            return head;
        Node* tail = head;
        while(tail!=NULL)
        {   
            if(tail->child != NULL)
            {   
                Node* front = tail->next;
                Node* temp = flatten(tail->child);
                tail->child = NULL;
                tail->next = temp;
                temp->prev = tail;
                while(tail->next!=NULL)
                {   
                    tail = tail->next;
                }
                tail->next = front;
                if(front!=NULL)
                    front->prev = tail;
            }
            else
            {   
                tail = tail->next;
            }
        }
        return head;
    }
};