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
    void solve(TreeNode* root, vector<string> &ans, string s){
        if(root == NULL){
            return;
        }

        if(root -> left == NULL && root -> right == NULL){
            s += to_string(root -> val);
            ans.push_back(s);
            return;
        }

        solve(root -> left, ans, s + to_string(root -> val) + "->");
        solve(root -> right, ans, s + to_string(root -> val) + "->");
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        solve(root, ans, "");
        return ans;
    }
};