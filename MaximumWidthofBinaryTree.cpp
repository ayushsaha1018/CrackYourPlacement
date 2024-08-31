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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int ans = 1;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()){
            int size = q.size();
            int start_index = q.front().second;
            int end_index = q.back().second;
            ans = max(ans, end_index - start_index + 1);

            while(size--){
                TreeNode* node = q.front().first;
                int idx = q.front().second;
                q.pop();

                int node_index = idx - start_index;

                if(node -> left)
                    q.push({node -> left, 2LL * node_index + 1});
                if(node -> right)
                    q.push({node -> right, 2LL * node_index + 2});
            }
        }

        return ans;
        
    }
};