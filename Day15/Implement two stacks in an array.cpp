// https://www.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends


class twoStacks {
  public:
    int arr[201];
    int s1;
    int s2;
    twoStacks() {
        s1 = -1;
        s2 = 201;
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        s1++;
        arr[s1] = x;
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        s2--;
        arr[s2] = x;
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        if(s1<0)
            return -1;
        int x = arr[s1];
        s1--;
        return x;
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        if(s2>200)
            return -1;
        int x = arr[s2];
        s2++;
        return x;
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    while (T--) {
        twoStacks *sq = new twoStacks();

        int Q;
        cin >> Q;
        while (Q--) {
            int stack_no;
            cin >> stack_no;
            int QueryType = 0;
            cin >> QueryType;

            if (QueryType == 1) {
                int a;
                cin >> a;
                if (stack_no == 1)
                    sq->push1(a);
                else if (stack_no == 2)
                    sq->push2(a);
            } else if (QueryType == 2) {
                if (stack_no == 1)
                    cout << sq->pop1() << " ";
                else if (stack_no == 2)
                    cout << sq->pop2() << " ";
            }
        }
        cout << endl;
    }
}

// } Driver Code Ends