// https://www.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1

//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node* solve(Node *head)
    {   
        int f = 0;
        if(head==NULL || head->next == NULL)
            return head;
        while(head->next!=NULL)
        {
            if(head->next->data > head->data)
            {   head = head->next;
                f = 1;
            }
            else
                break;
        }
        if(head->next==NULL)
            return head;
        Node* curr = head;
        Node* prev = head;
        while(curr->next!=NULL)
        {
            if(curr->next->data <= curr->data)
            {   
                prev = curr;
                curr = curr->next;
            }
            else
            {   
                prev->next = curr->next;
                curr = curr->next;
                f = 1;
            }
        }
        if(f)
            return solve(head);
        return head;
        // return head;
    }
    Node *compute(Node *head)
    {   
        return solve(head);
        // your code goes here
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends