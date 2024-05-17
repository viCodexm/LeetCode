class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        stack<TreeNode*> stack;
        TreeNode* currentNode = root, *lastRightNode = nullptr;

        while (!stack.empty() || currentNode) {
            while (currentNode) {
                stack.push(currentNode);
                currentNode = currentNode->left;
            }
            currentNode = stack.top();
            if (currentNode->right != lastRightNode && currentNode->right) {
                currentNode = currentNode->right;
                continue;
            }
            stack.pop();

            if (currentNode->right == nullptr && currentNode->left == nullptr && currentNode->val == target) {
                if (stack.empty())
                    return nullptr;
                TreeNode* parent = stack.top();
                (parent->left == currentNode) ? parent->left = nullptr : parent->right = nullptr;
            }
            lastRightNode = currentNode;
            currentNode = nullptr;
        }
        return root;
    }
};