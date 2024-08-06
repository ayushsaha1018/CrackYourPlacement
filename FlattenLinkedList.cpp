class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node* merge(Node* l1, Node* l2){
        Node* dummyHead = new Node(-1);
        Node* temp = dummyHead;
        
        while(l1 != NULL && l2 != NULL){
            if(l1 -> data < l2 -> data){
                temp -> bottom = l1;
                l1 = l1 -> bottom;
            }
            else{
                temp -> bottom = l2;
                l2 = l2 -> bottom;
            }
            temp -> next = NULL;
            temp = temp -> bottom;
        }
        
        if(l1 != NULL)
            temp -> bottom = l1;
        else
            temp -> bottom = l2;
        
        return dummyHead -> bottom;
    }
    
    Node *flatten(Node *root) {
        if(root == NULL || root -> next == NULL)
            return root;
        
        
        Node* mergedRoot = flatten(root -> next);
        return merge(root, mergedRoot);
    }
};