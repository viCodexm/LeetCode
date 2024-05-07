/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        if (dfs(head)) {
            ListNode* node = new ListNode(1, head);
            return node;
        }
        return head;
    }
    int dfs(ListNode* cur) {
        if (!cur) return 0;
        int leftover = cur->val > 4;
        cur->val = (cur->val * 2) % 10 + dfs(cur->next);
        return leftover;
    }
};