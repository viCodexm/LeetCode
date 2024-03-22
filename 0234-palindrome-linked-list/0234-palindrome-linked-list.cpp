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
    ListNode *front;
    bool isPalindrome(ListNode* head) {
        front = head;
        return dfs(head);
    }
    bool dfs(ListNode* cur) {
        if (cur) {
            if (!dfs(cur->next))
                return false;
            if (cur->val != front->val)
                return false;
            front = front->next;
        }
        return true;
    }
};