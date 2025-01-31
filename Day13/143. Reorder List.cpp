https://www.geeksforgeeks.org/problems/reorder-list/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{ 
public:
    Node* reverseList(Node* head)
    {   
        if(head==NULL)
            return head;
        Node *p = NULL, *c = head, *n = head->next;
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
    void reorderList(Node* head) {
        // Your code here
        if(head==NULL || head->next==NULL)
            return;
        Node *slow = head, *fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow = slow->next;
            if(fast->next!=NULL)
                fast = fast->next->next;
        }
        Node* middle = slow->next;
        slow->next = NULL;
        Node* j = reverseList(middle);
        Node* i = head;
        Node* dummy = i;
        Node* dummy1 = j;
        while(i!=NULL)
        {   
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

//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends