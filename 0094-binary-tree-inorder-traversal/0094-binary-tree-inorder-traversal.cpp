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

    void func(TreeNode* node, vector<int>& res){
        if(node == nullptr){
            return;
        }
        func(node->left, res);
        res.push_back(node->val);
        func(node->right, res);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        func(root, res);
        return res;
    }
};