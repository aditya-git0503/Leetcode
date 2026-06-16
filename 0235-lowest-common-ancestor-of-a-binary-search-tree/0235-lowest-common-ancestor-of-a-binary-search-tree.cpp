/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = root;
        TreeNode* ans;
        while(node != nullptr){
            if(p->val < node->val && q->val < node->val){
                node  = node ->left;
            }
            else if(p->val > node->val && q->val > node->val){
                node = node->right;
            }
            else{
                ans = node;
                break;
            }
        }
        return ans;
    }
};