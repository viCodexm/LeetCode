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
    vector<int> largestValues(TreeNode* root) {
        if (!root)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        while (!q.empty()) {
            const int size = q.size();
            int max = INT_MIN;
            for (int i = 0; i < size; ++i) {
                const TreeNode* cur = q.front(); q.pop();
                if (cur->right)
                    q.push(cur->right);
                if (cur->left)
                    q.push(cur->left);
                max = std::max(max, cur->val);
            }
            ans.push_back(max);
        }
        return ans;
    }
};