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
    bool isEvenOddTree(TreeNode* root) {
        if (!(root->val & 1))
            return false;
        queue<TreeNode*> q;
        q.push(root);
        bool odd = true;
        while (!q.empty()) {
            int size = q.size();
            vector<int> v;
            for (int i = 0; i < size; ++i) {
                TreeNode* left = q.front()->left;
                TreeNode* right = q.front()->right;
                if (left)
                    q.push(left);
                if (right)
                    q.push(right);
                v.push_back(q.front()->val);
                q.pop();
            }
            int vsize = v.size();
            if (odd) {
                if (!(v[0] & 1))
                    return false;
                for (int i = 1; i < vsize; ++i)
                    if (v[i - 1] >= v[i] || (!(v[i] & 1)))
                        return false;
            } else {
                if (v[0] & 1)
                    return false;
                for (int i = 1; i < vsize; ++i)
                    if (v[i - 1] <= v[i] || (v[i] & 1))
                        return false;
            }
            odd = !odd;
        }
        return true;
    }
};