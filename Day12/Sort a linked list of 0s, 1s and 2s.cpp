// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        if(head==NULL || head->next==NULL)
            return head;
        Node* zero = new Node(-1);
        Node* head0 = zero;
        Node* one = new Node(-1);
        Node* head1 = one;
        Node* two = new Node(-1);
        Node* head2 = two;
        Node* temp = head;
        while(temp!=NULL)
        {   
            if(temp->data == 0)
            {
                zero->next = temp;
                zero = zero->next;
            }
            else if(temp->data == 1)
            {
                one->next = temp;
                one = one->next;
            }
            else if(temp->data == 2)
            {
                two->next = temp;
                two = two->next;
            }
            temp = temp->next;
        }
        // zero->next = NULL;
        // one->next =NULL;
        // two->next =NULL;
        if(one->data==-1 && zero->data==-1)
            return head2->next;
        else if(one->data==-1)
        {
            zero->next = head2->next;
            return head0->next;
        }
        else if(zero->data==-1)
        {
            one->next = head2->next;
            return head1->next;
        }
        else
        {
            one->next = head2->next;
            zero->next = head1->next;
        }
        return head0->next;

    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends