class Node {
public:
    int val;
    int key;
    Node* prev;
    Node* next;
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:
    int size;
    unordered_map<int, Node*> mp;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    LRUCache(int capacity) {
        size = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void deleteNode(Node* p){
        Node* pre = p -> prev;
        Node* nex = p -> next;
        pre -> next = nex;
        nex -> prev = pre;
    }

    void addNode(Node* newNode){
        Node* temp = head -> next;
        head -> next = newNode;
        newNode -> prev = head;
        temp -> prev = newNode;
        newNode -> next = temp;
    }

    int get(int key) {
       if(mp.find(key) == mp.end())
         return -1;
        
       Node* currNode = mp[key];
       deleteNode(currNode);
       addNode(currNode);
       mp[key] = head -> next;
       return head -> next -> val;
    }

    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* currNode = mp[key];
            currNode -> val = value;
            deleteNode(currNode);
            addNode(currNode);
            mp[key] = head -> next;
        }
        else{
            if(mp.size() == size){
                Node* prev = tail -> prev;
                deleteNode(prev);
                mp.erase(prev -> key);
                Node* newNode = new Node(key, value);
                addNode(newNode);
                mp[key] = head -> next;
            }
            else{
                Node* newNode = new Node(key, value);
                addNode(newNode);
                mp[key] = head -> next;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */