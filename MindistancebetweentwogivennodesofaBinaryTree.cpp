class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* LCA(Node* root, int a, int b){
        if(root == NULL)
            return NULL;
        
        if(root -> data == a || root -> data == b)
            return root;
        
        Node* leftN = LCA(root -> left, a, b);
        Node* rightN = LCA(root -> right, a, b);
        
        if(leftN != NULL && rightN != NULL)
            return root;
        
        if(leftN != NULL)
            return leftN;
        
        return rightN;
    }
    
    int dist(Node* root, int n, int d){
        if(root == NULL)
            return -1;
         
        if(root -> data == n)
            return d;
        
        int left = dist(root -> left, n, d+1);
        if(left != -1)
            return left;
        return dist(root -> right, n, d+1);
    }
    
    int findDist(Node* root, int a, int b) {
        Node* lca = LCA(root, a, b);
        
        int d1 = dist(lca, a, 0);
        int d2 = dist(lca, b, 0);
        
        return d1 + d2;
    }
};