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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head, *slow = head;
        if (head->next == NULL)
            return NULL;
        int k = 1;
        if (n == 1) k = 0;
        while (fast)
        {
            fast = fast->next;
            if (k > n)
                slow = slow->next;
            k++;
        }
        if (n == 1)
            slow->next = NULL;
        else {
            slow->val = slow->next->val;
            slow->next = slow->next->next;
        }
        return head;
    }
};