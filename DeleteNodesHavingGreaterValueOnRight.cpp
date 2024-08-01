// TC : O(n), SC : O(1)

class Solution
{
    public:
    Node* reverse(Node* &head){
        Node* curr = head;
        Node* prev = NULL;
        Node* nextNode = NULL;
        while(curr != NULL){
            nextNode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        return prev;
    }
    
    Node *compute(Node *head)
    {
       if(head == NULL || head -> next == NULL)
            return head;
        
        head = reverse(head);
        
        int maxVal = head -> data;
        Node* prev = head;
        Node* curr = head -> next;
        while(curr != NULL){
            if(curr -> data < maxVal){
                prev -> next = curr -> next; 
                curr = curr -> next;
            }
            else{
                maxVal = max(maxVal, curr -> data);
                prev = curr;
                curr = curr -> next;
            }
        }
        
        return reverse(head);
    }
    
};