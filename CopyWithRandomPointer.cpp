// TC : O(n), SC : O(n)

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
   void insertAtTail(Node*& head, Node*& tail, int d)
    {
        Node* temp = new Node(d);
        if(head == NULL){
            head = temp;
            tail = temp;
        }
        else
        {
            tail -> next = temp;
            tail = temp;
        }
    }

    Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp =head;
        while(temp != NULL)
        {
            insertAtTail(cloneHead,cloneTail,temp -> val);
            temp = temp -> next;
        }

        unordered_map<Node*,Node*> linker;
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode != NULL)
        {
            linker[originalNode] = cloneNode;
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }

                
        cloneNode = cloneHead;
        originalNode = head;
        while(cloneNode != NULL)
        {
            cloneNode -> random = linker[originalNode-> random];
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }
        
        return cloneHead;
    }
};