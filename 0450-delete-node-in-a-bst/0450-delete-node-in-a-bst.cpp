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

    TreeNode* func(TreeNode* node){
        while(node->right != nullptr){
            node = node->right;
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr){
            return root;
        }
        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else{
            if(root->left == nullptr){
                return root->right;
            }
            else if(root->right == nullptr){
                return root->left;
            }
            else{
                TreeNode* pred = func(root->left);
                root->val = pred->val;
                root->left = deleteNode(root->left, pred->val);
            }
        }
        return root;
    }
};