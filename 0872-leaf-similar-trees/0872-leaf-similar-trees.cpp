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
    vector<int> tree1, tree2;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1, tree1);
        dfs(root2, tree2);
        return tree1 == tree2;
    }
    void dfs(TreeNode* cur, vector<int>& values) {
        if (!cur)
            return;
        if (!cur->left && !cur->right)
            values.push_back(cur->val);
        dfs(cur->left, values);
        dfs(cur->right, values);
    }
};