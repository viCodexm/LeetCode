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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = 0;
        for (ListNode* traverse = head; traverse; traverse = traverse->next)
            size++;
        
        int part_size = size / k;
        int extra = size % k;

        ListNode* tmp = head, *prev = NULL;
        vector<ListNode*> ans(k, NULL);
        for (int i = 0; i < k && tmp; ++i) {
            ans[i] = tmp;
            for (int j = 0; j < part_size; ++j) {
                prev = tmp;
                tmp = tmp->next;
            }
            if (extra) {
                prev = tmp;
                tmp = tmp->next;
                extra--;
            }
            prev->next = NULL;
        }
        return ans;
    }
};