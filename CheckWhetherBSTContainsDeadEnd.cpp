class Solution{
  public:
    void fillNodes(Node *root, map<int,int> &mp){
        if(root == NULL)
            return;
        
        mp[root -> data] = 1;
        fillNodes(root -> left, mp);
        fillNodes(root -> right, mp);
    }
    
    bool check(Node* root, map<int,int> &mp){
        if(root == NULL)
            return false;
        
        if(root -> left == NULL && root -> right == NULL){
            int prev = root -> data - 1;
            int next = root -> data + 1;
            
            if(mp.find(prev) != mp.end() && mp.find(next) != mp.end())
                return true;
        }
        
        return check(root -> left, mp) || check(root -> right, mp);
    }
  
    bool isDeadEnd(Node *root)
    {
        map<int,int> mp;
        mp[0] = 1;
        fillNodes(root, mp);
        
        return check(root, mp);
    }
};