class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        int size = inorder.size();
        return createBalancedBST(inorder, 0, size - 1);
    }

private:
    void inorderTraversal(TreeNode* root, vector<int>& inorder) {
        if (!root)
            return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }

    TreeNode* createBalancedBST(const vector<int>& inorder, int start, int end) {
        if (start > end)
            return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* leftSubtree = createBalancedBST(inorder, start, mid - 1);
        TreeNode* rightSubtree = createBalancedBST(inorder, mid + 1, end);
        return new TreeNode(inorder[mid], leftSubtree, rightSubtree);
    }
};