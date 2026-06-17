class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIndex;
        for (int i = 0; i < inorder.size(); i++)
            inorderIndex[inorder[i]] = i;

        int preIdx = 0;
        return build(preorder, 0, inorder.size() - 1, inorderIndex, preIdx);
    }

    TreeNode* build(vector<int>& preorder, int inLeft, int inRight,
                    unordered_map<int, int>& inorderIndex, int& preIdx) {
        if (inLeft > inRight)
            return nullptr; 

        int rootVal = preorder[preIdx++]; 
        TreeNode* root = new TreeNode(rootVal);

        int mid = inorderIndex[rootVal]; 

        root->left = build(preorder, inLeft, mid - 1, inorderIndex, preIdx);
        root->right = build(preorder, mid + 1, inRight, inorderIndex, preIdx);

        return root;
    }
};