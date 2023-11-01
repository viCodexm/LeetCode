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
    void traverse(TreeNode* root, unordered_map<int, int>& dict) {
        if (!root)
            return;
        dict[root->val]++;
        traverse(root->left, dict);
        traverse(root->right, dict);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> dict;
        traverse(root, dict);
        priority_queue<pair<int, int>> pq;
        for (auto [num, entrys] : dict)
            pq.push({entrys, num});
        
        vector<int> ans;
        int max = pq.top().first;
        while (!pq.empty() && pq.top().first == max) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};