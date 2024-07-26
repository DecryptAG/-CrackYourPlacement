// https://leetcode.com/problems/copy-list-with-random-pointer/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* temp = head;
        Node* ptr = new Node(-1);
        while(temp!=NULL)
        {   
            if(mp.find(temp)!=mp.end())
            {   
                // cout<<"fas"<<endl;
                ptr->next = mp[temp];
            }
            else
            {   
                // cout<<"afsd"<<endl;
                Node* newNode = new Node(temp->val);
                mp[temp] = newNode;
                ptr->next = newNode;
            }
            ptr = ptr->next;


            if(temp->random!=NULL)
            {
                if(mp.find(temp->random)!=mp.end())
                {
                    ptr->random = mp[temp->random];
                }
                else
                {
                    Node* newNode = new Node(temp->random->val);
                    mp[temp->random] = newNode;
                    ptr->random = newNode;
                }
            }
            temp = temp->next;
        }
        return mp[head];
    }
};