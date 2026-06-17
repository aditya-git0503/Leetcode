class Solution {
public:
    int globalMax = INT_MIN;
    
    int maxGain(TreeNode* node){
        if(node == nullptr){
            return 0;
        }
        int leftGain = max(0, maxGain(node->left));
        int rightGain = max(0, maxGain(node->right));

        globalMax = max(globalMax, node->val + leftGain + rightGain);
        return node->val + max(leftGain, rightGain);
    }
    
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return globalMax;
    }
};