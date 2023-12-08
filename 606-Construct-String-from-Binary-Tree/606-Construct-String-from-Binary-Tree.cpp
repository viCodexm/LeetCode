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
    void dfs(TreeNode* node, string& ans) {
        if (!node)
            return;
        ans += to_string(node->val);
        if (node->left || node->right) {
            ans += "(";
            dfs(node->left, ans);
            ans += ")";
            if (node->right) {
                ans += "(";
                dfs(node->right, ans);
                ans += ")";
            }
        }
    }
    string tree2str(TreeNode* root) {
        if (!root)
            return "";
        string ans = "";
        dfs(root, ans);
        return ans;
    }
};
