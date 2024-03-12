class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* front = new ListNode(0, head);
        ListNode* current = front;
        int prefixSum = 0;
        unordered_map<int, ListNode*> prefixSumToNode;
        while (current) {
            prefixSum += current->val;
            if (prefixSumToNode.find(prefixSum) != prefixSumToNode.end()) {
                ListNode* prev = prefixSumToNode[prefixSum];
                current = prev->next;
                int p = prefixSum + current->val;
                while (p != prefixSum) {
                    prefixSumToNode.erase(p);
                    current = current->next;
                    p += current->val;
                }
                prev->next = current->next;
            } else {
                prefixSumToNode[prefixSum] = current;
            }
            current = current->next;
        }
        return front->next;
    }
};