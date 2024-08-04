/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* leftRoot, TreeNode* rightRoot){
        if(leftRoot == NULL && rightRoot == NULL)
            return true;
        
        if(leftRoot == NULL || rightRoot == NULL || leftRoot -> val != rightRoot -> val){
            return false;
        }

        return solve(leftRoot -> left, rightRoot -> right) && solve(leftRoot -> right, rightRoot -> left);
    }

    bool isSymmetric(TreeNode* root) {
        return solve(root -> left, root -> right);
    }
};