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
    void reorderList(ListNode* head) {
        ListNode* cur = head;
        stack<ListNode*> st;
        while (cur->next) { st.push(cur); cur = cur->next; }
        ListNode* right = cur;
        ListNode* left = head;

        int done = 0, need = st.size() / 2;
        while (done < need && !st.empty()) {
            right->next = left->next;
            left->next = right;
            right = st.top();
            right->next = NULL;
            st.pop();
            left = left->next->next;
            done++;
        }
    }
};