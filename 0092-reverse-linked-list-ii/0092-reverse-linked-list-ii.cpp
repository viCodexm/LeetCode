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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head)
            return NULL;
        
        ListNode* collar = new ListNode();
        collar->next = head;
        
        ListNode* prev = collar;
        for (int i = 0; i < left - 1; ++i)
            prev = prev->next;
        
        ListNode* cur = prev->next;
        for (int i = 0; i < right - left; ++i) {
            ListNode* next = cur->next;
            cur->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }
        return collar->next;
    }
};