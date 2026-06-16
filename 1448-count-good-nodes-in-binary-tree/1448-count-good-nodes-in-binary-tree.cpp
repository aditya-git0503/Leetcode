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

    int dfs(TreeNode* node, int maxi){
        if(node == nullptr){
            return 0;
        }
        int count = 0;
        if(node->val >= maxi){
            count = 1;
        }
        maxi = max(node->val, maxi);
        return count + dfs(node->left, maxi) + dfs(node->right, maxi);
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};