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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newroot = new TreeNode(val);
            newroot->left = root;
            return newroot;
        }
        dfs(root, val, depth);
        return root;    
    }
    void dfs(TreeNode* cur, int val, int depth) {
        if (!cur || depth < 2)
            return;
        if (depth == 2) {
            TreeNode* node = cur->left;
            cur->left = new TreeNode(val);
            cur->left->left = node;
            
            node = cur->right;
            cur->right = new TreeNode(val);
            cur->right->right = node;
        }
        dfs(cur->left, val, depth - 1);
        dfs(cur->right, val, depth - 1);
    }
};