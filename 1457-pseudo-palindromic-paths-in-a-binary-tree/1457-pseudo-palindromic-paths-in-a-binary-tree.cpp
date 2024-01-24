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
    int pseudoPalindromicPaths(TreeNode* root) {
        vector<int> digits(10, 0);
        return dfs(root, digits);
    }
    int dfs(TreeNode* root, vector<int>& digits) {
        if (!root)
            return 0;

        digits[root->val]++;
        if (!root->left && !root->right) {
            int cnt = countOdd(digits);
            digits[root->val]--;
            return cnt <= 1;
        }

        int leftCount = dfs(root->left, digits);
        int rightCount = dfs(root->right, digits);
        digits[root->val]--;
        return leftCount + rightCount;
    }

    int countOdd(const vector<int>& digits) {
        int count = 0;
        for (int i = 1; i < 10; ++i)
            count += digits[i] & 1;
        return count;
    }
};