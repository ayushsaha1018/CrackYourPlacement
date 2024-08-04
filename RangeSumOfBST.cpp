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
    int ans = 0;
    void solve(TreeNode* root, int low, int high, int &sum){
        if(root == NULL)
            return;

        solve(root -> left, low, high, sum);
        if(root -> val >= low && root -> val <= high)
            ans += root -> val;
        
        if(root -> val > high)
            return;
        solve(root -> right, low, high, sum);
    }


    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        solve(root, low, high, sum);
        return ans;
    }
};