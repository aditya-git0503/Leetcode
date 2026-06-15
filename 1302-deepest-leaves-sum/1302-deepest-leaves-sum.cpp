class Solution {
public:
    int depth(TreeNode* node){
        if(node == nullptr){
            return 0;
        }
        return 1 + max(depth(node->left), depth(node->right));
    }

    void dfs(TreeNode* node, int currentDepth, int maxDepth, int& sum) {
        if (node == nullptr) return;
        
        if (currentDepth == maxDepth) {
            sum += node->val;
            return;
        }
        
        dfs(node->left, currentDepth + 1, maxDepth, sum);
        dfs(node->right, currentDepth + 1, maxDepth, sum);
    }

    int deepestLeavesSum(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }

        int d = depth(root);
        int sum = 0;
        dfs(root, 1, d, sum);
        
        return sum;
    }
};