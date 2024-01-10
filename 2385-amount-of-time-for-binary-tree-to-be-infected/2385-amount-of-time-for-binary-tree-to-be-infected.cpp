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
    void dfs(TreeNode* root, int prev, unordered_map<int, vector<int>>& dict) {
        if (!root)
            return;
        if (prev)
            dict[root->val].push_back(prev);
        if (root->left)
            dict[root->val].push_back(root->left->val);
        if (root->right)
            dict[root->val].push_back(root->right->val);
        dfs(root->left, root->val, dict);
        dfs(root->right, root->val, dict);
    }
    int amountOfTime(TreeNode* root, int start) {
        if (!root->left && !root->right)
            return 0;
        unordered_map<int, vector<int>> dict;
        dfs(root, 0, dict);
        int spread = 0;
        unordered_set<int> vis; vis.insert(start);
        queue<int> q; q.push(start);

        while (!q.empty()) {
            int level = q.size();
            for (int i = 0; i < level; ++i) {
                int cur = q.front(); q.pop();
                for (int& nei : dict[cur])
                    if (vis.find(nei) == vis.end()) {
                        vis.insert(nei);
                        q.push(nei);
                    }
            }
            spread++;
        }
        return spread - 1;
    }
};