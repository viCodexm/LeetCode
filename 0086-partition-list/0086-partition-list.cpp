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
    ListNode* partition(ListNode* head, int x) {
        if (!head)
            return head;
        vector<ListNode*> before, after;
        while (head) {
            if (head->val < x)
                before.push_back(head);
            else after.push_back(head);
            head = head->next;
        }
        int pref = before.size();
        for (int i = 0; i < pref - 1; ++i)
            before[i]->next = before[i + 1];
        if (!after.empty() && pref > 0)
            before[pref - 1]->next = after[0];

        int suf = after.size();
        for (int i = 0; i < suf - 1; ++i)
            after[i]->next = after[i + 1];
        if (suf > 0)
            after[suf - 1]->next = NULL;
        if (before.empty())
            return after[0];
        return before[0];
    }
};