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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return build(0, inorder.size() - 1, idx, preorder, inorder);
    }
    TreeNode* build(int start, int end, int& idx, vector<int>& preorder, vector<int>& inorder) {
        if (start > end)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[idx]);

        int split = 0;
        for (int i = 0; i < inorder.size(); ++i)
            if (preorder[idx] == inorder[i]) {
                split = i;
                break;
            }
        idx++;
        root->left = build(start, split - 1, idx, preorder, inorder);
        root->right = build(split + 1, end, idx, preorder, inorder);
        return root;
    }
};