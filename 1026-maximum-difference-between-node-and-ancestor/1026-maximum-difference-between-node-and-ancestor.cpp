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
    int dfs(TreeNode* cur, int min, int max) {
        if (!cur)
            return 0;
        min = std::min(min, cur->val);
        max = std::max(max, cur->val);
        
        return std::max({cur->val - min, max - cur->val, dfs(cur->left, min, max), dfs(cur->right, min, max)});
    }
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
};