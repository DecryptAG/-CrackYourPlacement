// https://www.geeksforgeeks.org/problems/median-of-bst/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



float findMedian(struct Node* node);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));
 
   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   //cout << t << endl;
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

      // getline(cin, s);
       
        cout << findMedian(root) << endl;

      // cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends


/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Function should return median of the BST
void inorder(Node* root,int &n)
{
    if(root == NULL)
        return;
    inorder(root->left,n);
    n++;
    inorder(root->right,n);
}
void getNodes(Node* root,int &curr, int &prev,int &n,int N)
{
    if(root == NULL)
        return;
    getNodes(root->left,curr,prev,n,N);
     n++;
    if(n<= N/2+1)
    {
        prev = curr;
        curr = root->data;
        // cout<<n<<endl;
        // cout<<curr<<" "<<prev<<endl;
       
    } 
    if(n == N/2+1)
        return; 
   
    
    getNodes(root->right,curr,prev,n,N);
}
float findMedian(struct Node *root)
{   
    int N = 0;
    inorder(root,N);
    // cout<<N<<endl;
    int curr = 0;
    int prev = 0;
    int n = 0;
    getNodes(root,curr,prev,n,N);
    // cout<<curr<<" "<<prev<<endl;
    if(N%2==0)
        return (curr + prev)/2.0;
    return curr;
      //Code here
}

// 1 3 6 10 11 12 13 15 18 20
