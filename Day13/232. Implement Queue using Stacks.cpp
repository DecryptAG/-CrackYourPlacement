// https://leetcode.com/problems/implement-queue-using-stacks/description/

class MyQueue {
public:
    stack<int> st1,st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(st2.size()!=0)
            {
                int x = st2.top();
                st2.pop();
                return x;
            }
        else
        {
            while(st1.size()>0)
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        if(st2.size()!=0)
            {
                int x = st2.top();
                st2.pop();
                return x;
            }
        return -1;
    }
    
    int peek() {
        if(st2.size()!=0)
            {
                int x = st2.top();
                return x;
            }
        else
        {
            while(st1.size()>0)
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        if(st2.size()!=0)
            {
                int x = st2.top();
                return x;
            }
        else
            return -1;
    }
    
    bool empty() {
        if(st1.size()==0 && st2.size()==0)
            return true;
        else
            return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */