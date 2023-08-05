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
    map<pair<int, int>, vector<TreeNode*>> dp;
public:
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n);
    }
    vector<TreeNode*> dfs(int start, int end) {
        vector<TreeNode*> ans;
        if (start > end) {
            ans.push_back(NULL);
            return ans;
        }
        if (dp.count({start, end}))
            return dp[{start, end}];

        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> leftSubTree = dfs(start, i - 1);
            vector<TreeNode*> rightSubTree = dfs(i + 1, end);
            for (TreeNode* left : leftSubTree)
                for (TreeNode* right : rightSubTree) {
                    TreeNode* cur = new TreeNode(i);
                    cur->left = left;
                    cur->right = right;
                    ans.push_back(cur);
                }
        }
        dp[{start, end}] = ans;
        return ans;
    }
};