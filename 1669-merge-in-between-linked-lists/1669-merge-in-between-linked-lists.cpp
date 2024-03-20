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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *head = list1, *entry, *end;
        ListNode* cur = list1;
        for (int i = 1; cur->next; cur = cur->next, ++i) {
            if (i == a)
                entry = cur;
            else if (i == b+1)
                end = cur->next;
        }
        entry->next = list2;
        cur = list2;
        for (; cur->next; cur = cur->next) {}
        cur->next = end;
        return head;
    }
};