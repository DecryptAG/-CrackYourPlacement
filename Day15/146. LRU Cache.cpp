// https://leetcode.com/problems/lru-cache/description/

struct Node{
    Node *next;
    pair<int,int> val;
    Node *prev;
    Node(){

    }
    Node(int k, int n){
        val = {k,n};
    }
};
class LRUCache {
public:
    int size;
    Node* head;
    Node* tail;
    unordered_map<int,Node*> mp;
    LRUCache(int capacity) {
        size = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->val = {-1,-1};
        head->next = tail;
        tail->val = {-1,-1};
    }
    void deleteNode(int key)
    {
        Node* temp = mp[key];
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        mp.erase(key);
        size++;
    }
    void addNode(int key,int val)
    {
        Node* temp = new Node(key,val);
        mp[key] = temp;
        temp->next = head->next;
        temp->prev = head;
        head->next->prev = temp;
        head->next = temp;
        size--;
    }
    void print()
    {
        Node* temp = head;
        while(temp!=NULL)
        {
            cout<<temp->val.first<<" "<<temp->val.second<<endl;
            temp = temp->next;
        }
    }
    int get(int key) {
        // if(key==2)
        //     // print();
        if(mp.find(key)==mp.end())
            return -1;
        int value = mp[key]->val.second;
        deleteNode(key);
        addNode(key,value);
        return value;
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end())
        {   
            if(size == 0)
            {
                deleteNode(tail->prev->val.first);
            }
            addNode(key,value);
        }
        else
        {
            int old_val = mp[key]->val.second;
            deleteNode(key);
            addNode(key,value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */