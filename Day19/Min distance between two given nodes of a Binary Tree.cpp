// https://www.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1

//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    void getDis(Node* root,Node* dest, int dis, int &ans)
    {
        if(root == NULL)
            return;
        if(root == dest)
        {   
            ans = dis;
            // cout<<"ans"<<ans<<endl;
            return;
        }
        getDis(root->left,dest,dis+1,ans);
        getDis(root->right,dest,dis+1,ans);
        
    }
    Node* getLca(Node* root, Node* a, Node* b)
    {
        if(root == NULL || root == a || root == b)
            return root;
        Node* left = getLca(root->left,a,b);
        Node* right = getLca(root->right,a,b);
        if(left==NULL)
            return right;
        else if(right == NULL)
            return left;
        return root;
    }
    Node* getNode(Node* root, int a)
    {
        if(root == NULL)
            return root;
        Node* left = getNode(root->left,a);
        Node* right = getNode(root->right,a);
        if(left && left->data == a)
            return left;
        if(right && right->data == a)
            return right;
        return root;
    }
    int findDist(Node* root, int a, int b) {
        Node* aNode = getNode(root,a);
        Node* bNode = getNode(root,b);
        Node* lca = getLca(root,aNode,bNode);
        // cout<<aNode->data<<endl;
        // cout<<bNode->data<<endl;
        // cout<<lca->data<<endl;
        int x = 0;
        int y = 0;
        getDis(lca,aNode,0,x);
        getDis(lca,bNode,0,y);
        // cout<<x<<" "<<y<<endl;
        return x+y;
        // Your code here
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends